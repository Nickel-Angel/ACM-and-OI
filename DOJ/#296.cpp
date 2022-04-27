/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, par[2010], size[2010], h[2010];
int head[2010], to[2010], next[2010], tot;
long long f[2010][2010][2], g[2010][2];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    size[u] = 1;
    f[u][0][0] = h[u], f[u][1][0] = 1e14;
    f[u][0][1] = 1e14, f[u][1][1] = 0;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        for (int i = 0; i <= size[u] + size[v]; ++i)
            g[i][0] = 1e14, g[i][1] = 1e14;
        for (int i = 0; i <= size[u]; ++i)
        {
            for (int j = 0; j <= size[v]; ++j)
            {
                g[i + j][0] = min(g[i + j][0], f[u][i][0] + f[v][j][0] + h[v]);
                g[i + j][0] = min(g[i + j][0], f[u][i][0] + f[v][j][1]);
                g[i + j][1] = min(g[i + j][1], f[u][i][1] + min(f[v][j][0], f[v][j][1]));
            }
        }
        for (int i = 0; i <= size[u] + size[v]; ++i)
            f[u][i][0] = g[i][0], f[u][i][1] = g[i][1];
        size[u] += size[v];
    }
}

inline void solve()
{
    scanf("%d", &n);
    memset(head, 0, sizeof(head));
    tot = 0;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        add_edge(par[i], i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", h + i);
    dfs(1);
    for (int i = 0; i <= n; ++i)
        printf("%lld%c", min(f[1][i][0], f[1][i][1]), " \n"[i == n]);
}   

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}