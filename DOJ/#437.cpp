/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

int n, k, m, val[110][110];
int f[110][110][110];

int dfs(int u, int b, int step)
{
    if (f[u][b][step] != -1)
        return f[u][b][step];
    int &res = f[u][b][step] = 0x3f3f3f3f;
    if (step == 0)
    {
        res = 0;
        return 0;
    }
    for (int i = min(u, b) + 1; i < max(u, b); ++i)
        res = min(res, min(dfs(i, u, step - 1), dfs(i, b, step - 1)) + val[u][i]);     
    return res;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    memset(val, 0x3f, sizeof(val));
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        val[u][v] = min(val[u][v], w);
    }
    memset(f, -1, sizeof(f));
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, min(dfs(i, 0, k - 1), dfs(i, n + 1, k - 1)));
    printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
    return 0;
}