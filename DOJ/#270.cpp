/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

int n, q, a[50010], par[50010], head[50010], to[50010], next[50010], tot;
int f[50010][110], size[50010];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    f[u][0] = a[u];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        for (int i = min(99, size[u]); i >= 0; --i)
        {
            for (int j = min(98 - i, size[v] - 1); j >= 0; --j)
            {
                f[u][i + j + 1] = max(f[u][i + j + 1], f[u][i] + f[v][j]);
            }
        }
        size[u] += size[v];
    }
    ++size[u];
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
        printf("%d\n", f[u][m - 1]);
    }
    return 0;
}