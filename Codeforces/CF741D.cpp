/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;

const int maxn = 5e5 + 10;
int n, par[maxn], size[maxn], son[maxn], depth[maxn];
int rev[maxn], L[maxn], R[maxn], dfs_t;
int head[maxn], to[maxn], next[maxn], val[maxn], tot;
int dis[maxn], ans[maxn], b[20 * maxn];

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u)
{
    size[u] = 1, depth[u] = depth[par[u]] + 1;
    L[u] = ++dfs_t, rev[dfs_t] = u;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dis[v] = dis[u] ^ val[c];
        dfs_son(v);
        size[u] += size[v];
        if (size[son[u]] < size[v])
            son[u] = v;
    }
    R[u] = dfs_t;
}

void dfs_solve(int u, bool keep)
{
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == son[u])
            continue;
        dfs_solve(v, false);
        ans[u] = max(ans[u], ans[v]);
    }
    if (son[u])
        dfs_solve(son[u], true), ans[u] = max(ans[u], ans[son[u]]);
    if (b[dis[u]])
        ans[u] = max(ans[u], b[dis[u]] - depth[u]);
    for (int i = 0; i < 22; ++i)
    {
        if (b[dis[u] ^ (1 << i)])
            ans[u] = max(ans[u], b[dis[u] ^ (1 << i)] - depth[u]);
    }
    b[dis[u]] = max(b[dis[u]], depth[u]);
    for (int c = head[u], v, x; c; c = next[c])
    {
        v = to[c];
        if (v == son[u])
            continue;
        for (int i = L[v]; i <= R[v]; ++i)
        {
            x = rev[i];
            if (b[dis[x]])
                ans[u] = max(ans[u], depth[x] + b[dis[x]] - 2 * depth[u]);
            for (int j = 0; j < 22; ++j)
            {
                if (b[dis[x] ^ (1 << j)])
                    ans[u] = max(ans[u], depth[x] + b[dis[x] ^ (1 << j)] - 2 * depth[u]);
            }
        }
        for (int i = L[v]; i <= R[v]; ++i)
        {
            x = rev[i];
            b[dis[x]] = max(b[dis[x]], depth[x]);
        }
    }
    if (!keep)
    {
        for (int i = L[u], x; i <= R[u]; ++i)
        {
            x = rev[i];
            b[dis[x]] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        char c;
        scanf("%d %c", par + i, &c);
        add_edge(par[i], i, 1 << (c - 'a'));
    }
    dfs_son(1), dfs_solve(1, true);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);  
    return 0;
}