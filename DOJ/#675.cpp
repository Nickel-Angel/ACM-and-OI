/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, cnt[4];
long double f[310][310][310];
bool vis[310][310][310];

long double dfs(int i, int j, int k)
{
    if (vis[i][j][k])
        return f[i][j][k];
    vis[i][j][k] = true;
    long double& res = f[i][j][k];
    res = 1.0 * n / (i + j + k);
    if (i > 0)
        res += i * dfs(i - 1, j + 1, k) / (i + j + k);
    if (j > 0)
        res += j * dfs(i, j - 1, k + 1) / (i + j + k);
    if (k > 0)
        res += k * dfs(i, j, k - 1) / (i + j + k);
    return res; 
}

int main()
{
    scanf("%d", &n);
    vis[0][0][0] = true;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        ++cnt[x];
    }
    printf("%.12Lf\n", dfs(cnt[3], cnt[2], cnt[1]));
    return 0;
}