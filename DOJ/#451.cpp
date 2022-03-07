/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, m, a[maxn], size[maxn], son[maxn], par[maxn], depth[maxn];
int top[maxn], dfn[maxn], sum[maxn], tim;
int head[maxn], to[maxn << 1], next[maxn << 1], tot;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u, int pre)
{
    par[u] = pre, size[u] = 1, depth[u] = depth[pre] + 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs_son(v, u);
        size[u] += size[v];
        if (size[son[u]] < size[v])
            son[u] = v;
    }
}

void dfs_top(int u, int anc)
{
    top[u] = anc;
    dfn[u] = ++tim;
    if (!son[u])
    {
        sum[u] = a[u];
        return;
    }
    dfs_top(son[u], anc);
    sum[u] = sum[son[u]] ^ a[u];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == par[u] || v == son[u])
            continue;
        dfs_top(v, v);
    }
}

inline int query(int x, int y)
{
    int res = 0;
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
        res ^= a[x] ^ sum[x] ^ sum[top[x]];
        x = par[top[x]];
    }
    if (depth[x] > depth[y])
        std::swap(x, y);
    res ^= a[y] ^ sum[x] ^ sum[y];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs_son(1, 0), dfs_top(1, 1);
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}