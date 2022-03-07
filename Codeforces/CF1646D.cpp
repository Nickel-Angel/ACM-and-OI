/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 2e5 + 10;
int n, f[maxn][2], g[maxn][2], best[maxn], w[maxn];
std::vector<int> e[maxn];

void dfs_solve(int u, int pre)
{
    f[u][0] = 1;
    f[u][1] = e[u].size(), g[u][1] = 1;
    for (int v : e[u])
    {
        if (v == pre)
            continue;
        dfs_solve(v, u);
        f[u][1] += f[v][0], g[u][1] += g[v][0];
        f[u][0] += f[v][best[v]], g[u][0] += g[v][best[v]];
    }
    if (g[u][0] < g[u][1] || (g[u][0] == g[u][1] && f[u][0] > f[u][1]))
        best[u] = 1;
    else
        best[u] = 0;
}

void dfs_calc(int u, int pre, int flag)
{
    w[u] = flag ? e[u].size() : 1;
    for (int v : e[u])
    {
        if (v == pre)
            continue;
        dfs_calc(v, u, flag ? 0 : best[v]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
    }
    if (n == 2)
    {
        puts("2 2");
        puts("1 1");
        return 0;
    }
    dfs_solve(1, 0), dfs_calc(1, 0, best[1]);
    printf("%d %d\n", g[1][best[1]], f[1][best[1]]);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", w[i], " \n"[i == n]);
    return 0;
}