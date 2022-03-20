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
int n, a[maxn], head[maxn], to[maxn << 1], next[maxn << 1], tot;
int f[maxn][2], g[maxn][2], ans;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    int fir_up = 0, sec_up = 0, fir_down = 0, sec_down = 0;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        if ((a[v] + 1) % 3 == a[u])
        {
            if (f[v][0] + 1 >= f[u][0])
            {
                sec_up = fir_up;
                f[u][1] = f[u][0];
                fir_up = v;
                f[u][0] = f[v][0] + 1;
            }
            else if (f[v][0] + 1 > f[u][1])
            {
                sec_up = v;
                f[u][1] = f[v][0] + 1;
            }
        }
        if ((a[u] + 1) % 3 == a[v])
        {
            if (g[v][0] + 1 >= g[u][0])
            {
                sec_down = fir_down;
                g[u][1] = g[u][0];
                fir_down = v;
                g[u][0] = g[v][0] + 1;
            }
            else if (g[v][0] + 1 > g[u][1])
            {
                sec_down = v;
                g[u][1] = g[v][0] + 1;
            }
        }
    }
    if (fir_up == fir_down)
        ans = max(ans, max(f[u][0] + g[u][1], f[u][1] + g[u][0]) + 1);
    else
        ans = max(ans, f[u][0] + g[u][0] + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}