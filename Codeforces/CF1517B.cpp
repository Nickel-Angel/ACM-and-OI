/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, m, b[110][110], val[10010], id[10010];
int lock[110][110], vis[110][2], p[110];

inline void solve()
{
    scanf("%d%d", &n, &m);
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", b[i] + j);
            val[++tot] = b[i][j];
            id[tot] = tot;
            lock[i][j] = 0;
        }
    }
    sort(id + 1, id + tot + 1, [&](int x, int y){return val[x] < val[y];});
    for (int i = 1; i <= m; ++i)
    {
        vis[i][0] = vis[i][1] = 0;
        lock[(id[i] - 1) / m + 1][(id[i] - 1) % m + 1] = i;
        //printf("c %d %d %d %d\n", val[id[i]], id[i] / m + 1, id % m + 1, i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (lock[i][j])
            {
                //printf("l %d %d %d\n", lock[i][j], b[i][j], j);
                p[lock[i][j]] = b[i][j];
                vis[lock[i][j]][0] = i;
                vis[j][1] = i;
            }
        }
        for (int j = 1, k = 1; j <= m; ++j)
        {
            if (vis[j][0] == i)
                continue;
            while (vis[k][1] == i)
                ++k;
            p[j] = b[i][k];
            ++k;
        }
        for (int j = 1; j <= m; ++j)
            printf("%d%c", p[j], " \n"[j == m]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}