/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 3e5 + 10;
int n, color[maxn], par[maxn], black[maxn], ans[maxn];
int head[maxn], to[maxn << 1], next[maxn << 1], tot;
bool lock[maxn];
std::vector<int> line;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    par[u] = pre;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        black[u] += black[v];
    }
}

void dfs_paint(int u)
{
    if (lock[u] || color[u] == 1)
        return;
    ans[u] = 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == par[u])
            continue;
        dfs_paint(v);
    }
}

int main()
{
    scanf("%d", &n);
    int root = 0, key = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", color + i);
        if (color[i] == 1)
        {
            ++black[i];
            if (!root)
                root = i;
            else
                key = i;
        }
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(root, 0);
    int u = par[key];
    bool flag = false;
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 0 || i == root)
            continue;
        flag |= (black[par[i]] > 1);
    }
    if (u == root || flag)
    {
        for (int i = 1; i <= n; ++i)
            printf("1 ");
        return 0;
    }
    line.push_back(key);
    line.push_back(u);
    u = par[u];
    while (u != root)
    {
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (v == root)
                continue;
            flag |= (color[v] == 1);
        }
        line.push_back(u);
        u = par[u];
    }
    if (flag || black[root] - 1 > black[line.back()] || black[line.back()] > black[line[line.size() - 2]])
    {
        for (int i = 1; i <= n; ++i)
            printf("1 ");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 1)
            lock[par[i]] = true;
    }
    dfs_paint(line[line.size() - 2]);
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i] ^ 1);
    return 0;
}