/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <cstring>
#include <cstdio>

int n, q, a[2010], par[2010], head[2010], to[2010], next[2010], tot;
int f[2010][2010], size[2010];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline int max(int x, int y)
{
    return x < y ? y : x;
}

void dfs(int u)
{
    size[u] = 1, f[u][1] = a[u], f[u][0] = 0;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        for (int i = size[u]; i > 0; --i)
        {   
            for (int j = size[v]; j >= 0; --j)
            {
                f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
            }
        }
        size[u] += size[v];
    }
}

int main()
{
    memset(f, -0x3f, sizeof(f));
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        add_edge(par[i], i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    dfs(1);
    int u, m;
    while (q--)
    {
        scanf("%d%d", &u, &m);
        printf("%d\n", f[u][m]);
    }
    return 0;
}