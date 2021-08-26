#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int maxn = 1e3 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], tot = 0;
int depth[maxn], par[maxn], son[maxn], size[maxn];
int top[maxn], dfn[maxn], timer = 0;
std::vector<int> e[maxn];

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
        add_edge(u, v);
        dfs_tree(v, u);
        size[u] += size[v];
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
    }
}