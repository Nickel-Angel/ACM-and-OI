/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m;
int head[310], to[310], next[310], tot;
int s[310], size[310], f[310][310], g[310];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        for (int i = 0; i <= size[u] + size[v]; ++i)
            g[i] = 0;
        for (int i = 0; i <= size[u]; ++i)
        {
            for (int j = 0; j <= size[v]; ++j)
            {
                g[i + j] = std::max(g[i + j], f[u][i] + f[v][j]);
            }
        }
        for (int i = 0; i <= size[u] + size[v]; ++i)
            f[u][i] = g[i];
        size[u] += size[v];
    }
    ++size[u];
    for (int i = size[u]; i > 0; --i)
        f[u][i] = f[u][i - 1] + s[u];
}

int main()
{
    scanf("%d%d", &n, &m);
    ++m;
    for (int i = 1, p; i <= n; ++i)
    {
        scanf("%d%d", &p, s + i);
        add_edge(p, i);
    }
    dfs(0);
    printf("%d\n", f[0][m]);
    return 0;
}