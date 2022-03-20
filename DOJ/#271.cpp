/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, a[1010], w[1010], par[1010], rev[1010], dfn[1010], R[1010], timer;
int head[1010], to[1010], next[1010], tot, f[1010][10010];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    dfn[u] = ++timer;
    rev[timer] = u;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
    }
    R[u] = timer + 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        add_edge(par[i], i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    dfs(1);
    for (int i = 1; i <= m; ++i)
        f[n + 1][i] = -0x3f3f3f3f;
    for (int i = n; i > 0; --i)
    {
        for (int j = 0; j <= m; ++j)
        {
            f[i][j] = f[R[rev[i]]][j];
            if (j >= w[rev[i]])
                f[i][j] = std::max(f[i][j], f[i + 1][j - w[rev[i]]] + a[rev[i]]);
        }
    }
    for (int i = 0; i <= m; ++i)
        printf("%d\n", f[1][i] > 0 ? f[1][i] : 0);
    return 0;
}