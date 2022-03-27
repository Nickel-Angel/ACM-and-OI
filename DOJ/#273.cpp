/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <vector>

using std::array;
using std::vector;

const long long inf = 1e14;
int n, m, par[2010], depth[2010];
int head[2010], to[2010], next[2010], tot;
long long f[2010][2010];   
vector<array<int, 2>> path[2010];

inline void merge(long long *a, long long *b, int bound)
{
    static long long suf_a[2010], suf_b[2010];
    suf_a[bound + 1] = suf_b[bound + 1] = inf;
    for (int i = bound; i > 0; --i)
    {
        suf_a[i] = std::min(suf_a[i + 1], a[i]);
        suf_b[i] = std::min(suf_b[i + 1], b[i]);
    }
    for (int i = 1; i <= bound; ++i)
        a[i] = std::min(a[i] + suf_b[i], b[i] + suf_a[i]);
}

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    for (int i = 1; i <= depth[u]; ++i)
        f[u][i] = inf;
    for (auto p : path[u])
        f[u][depth[p[0]]] = std::min(f[u][depth[p[0]]], 1ll * p[1]);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        merge(f[u], f[v], depth[v]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    depth[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        add_edge(par[i], i);
        depth[i] = depth[par[i]] + 1;
    }
    for (int i = 1, x, y, w; i <= m; ++i)
    {
        scanf("%d%d%d", &x, &y, &w);
        path[y].push_back({x, w});
    }
    dfs(1);
    printf("%lld\n", f[1][1] >= inf ? -1 : f[1][1]);
    return 0;
}