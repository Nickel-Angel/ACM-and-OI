/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::array;
using std::vector;

int n, m, par[2010], depth[2010], head[2010], to[4010], next[4010], tot;
long long f[2010], sum[2010];

vector<array<int, 3>> path[2010];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_init(int u)
{
    depth[u] = depth[par[u]] + 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs_init(v);
    }
}

inline int lca(int x, int y)
{
    while (x != y)
    {
        if (depth[x] > depth[y])
            x = par[x];
        else
            y = par[y];
    }
    return x;
}

void dfs_solve(int u)
{
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs_solve(v);
        sum[u] += f[v];
    }
    f[u] = sum[u];
    for (auto p : path[u])
    {
        long long res = sum[u] + p[2];
        int v = p[0];
        while (v != u)
        {
            res += sum[v] - f[v];
            v = par[v];
        }
        v = p[1];
        while (v != u)
        {
            res += sum[v] - f[v];
            v = par[v];
        }
        f[u] = max(f[u], res);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        add_edge(par[i], i);
    }
    dfs_init(1);
    for (int i = 1, x, y, w; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &w);
        path[lca(x, y)].push_back({x, y, w});
    }
    dfs_solve(1);
    printf("%lld\n", f[1]);
    return 0;
}