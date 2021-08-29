/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

using std::swap;

const int maxn = 1e3 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], tot = 0;
int depth[maxn], par[maxn], son[maxn], size[maxn], deg[maxn], match[maxn];
int top[maxn], dfn[maxn], timer = 0;
bool covered[maxn];
std::vector<int> e[maxn], leaf;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_tree(int u, int pre)
{
    size[u] = 1, par[u] = pre, depth[u] = depth[pre] + 1;
    for (auto v : e[u])
    {
        if (size[v])
            continue;
        add_edge(u, v), add_edge(v, u);
        dfs_tree(v, u);
        ++deg[u], ++deg[v];
        size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs_top(int u, int anc)
{
    top[u] = anc;
    dfn[u] = ++timer;
    if (son[u])
        dfs_top(son[u], anc);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == par[u] || v == son[u])
            continue;
        dfs_top(v, v);
    }
}

inline int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        x = par[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
}

inline void cover(int x, int y)
{
    while (x != y)
    {
        if (depth[x] < depth[y])
        {
            covered[y] = true;
            y = par[y];
        }
        else
        {
            covered[x] = true;
            x = par[x];
        }
    }
    covered[x] = true;
}

inline void match_leaf(int x, int y)
{
    match[x] = y, match[y] = x;
    cover(x, y);
}

inline int find_leaf(int u)
{
    int pre = u;
    while (deg[u] != 1)
    {
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (v != pre)
            {
                pre = u;
                u = v;
                break;
            }
        }
    }
    return u;
}

inline void path(int x, int y)
{
    if (x == n + 1) 
        x = 1;
    if (y == n + 1)
        y = 1;
    int anc = lca(x, y);
    std::vector<int> p1, p2;
    while (x != anc)
    {
        p1.push_back(x);
        x = par[x];
    }
    while (y != anc)
    {
        p2.push_back(y);
        y = par[y];
    }
    printf("%d ", p1.size() + p2.size() + 1);
    for (auto it = p1.begin(); it != p1.end(); ++it)
        printf("%d ", *it);
    printf("%d ", anc);
    for (auto it = p2.rbegin(); it != p2.rend(); ++it)
        printf("%d ", *it);
    puts("");
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs_tree(1, 0), dfs_top(1, 1);
    for (int i = 2; i <= n; ++i)
    {
        if (deg[i] == 1)
            leaf.push_back(i);
    }
    if (leaf.size() >= n / 3)
    {
        printf("2\n");
        for (int i = 0; i < n / 3; ++i)
            printf("%d ", leaf[i]);
        return 0;
    }
    if (deg[1] == 1)
        leaf.push_back(1);
    if (leaf.size() & 1)
    {
        par[n + 1] = 1, deg[n + 1] = 1, depth[n + 1] = 2;
        leaf.push_back(n + 1), add_edge(1, n + 1), add_edge(n + 1, 1);
    }
    for (unsigned i = 0; i < leaf.size(); i += 2)
        match_leaf(leaf[i], leaf[i + 1]);
    for (int i = 1; i <= n; ++i)
    {
        if (covered[i])
            continue;
        int cnt = 0, leaf1, leaf2, leaf3, leaf4;
        for (int c = head[i], v; c; c = next[c])
        {
            v = to[c];
            ++cnt;
            if (cnt == 1)
            {
                leaf1 = find_leaf(v);
                leaf2 = match[leaf1];
            }
            else if (cnt == 2)
            {
                leaf3 = find_leaf(v);
                leaf4 = match[leaf3];
                break;
            }
        }
        match_leaf(leaf1, leaf3), match_leaf(leaf2, leaf4);
    }
    int rest = (n + 5) / 6;
    printf("1\n");
    for (unsigned i = 0; i < leaf.size(); ++i)
    {
        if (leaf[i] == n + 1 && match[n + 1] == match[1])
            continue;
        if (leaf[i] < match[leaf[i]])
        {
            path(leaf[i], match[leaf[i]]);
            --rest;
        }
    }
    for (int i = 2; i <= rest + 1; ++i)
        printf("1 %d\n", i);
    return 0;
}