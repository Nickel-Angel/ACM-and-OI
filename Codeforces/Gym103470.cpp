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

const int maxn = 1e5 + 10;
int n, a[maxn], t[maxn];
int head[maxn], to[maxn << 1], next[maxn << 1], tot;
ll f[maxn], g[maxn], h[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    ll sumg = 0, normal_fir = 0, fir_val = 0, sec_val = 0, fir = 0, sec = 0;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        normal_fir = max(normal_fir, (ll)a[v]);
        if (t[v] == 3)
        {
            if (a[v] >= fir_val)
            {
                sec_val = fir_val, sec = fir;
                fir_val = a[v], fir = v; 
            }
            else if (a[v] > sec_val)
                sec_val = a[v], sec = v;
        }
        dfs(v, u);
        sumg += g[v];
    }
    h[u] = a[u] + sumg;
    g[u] = normal_fir + sumg;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        g[u] = max(g[u], h[v] + sumg - g[v] + (fir == v ? sec_val : fir_val));
    }
    f[u] = g[u] + a[u];
}   

inline void solve()
{
    memset(head, 0, sizeof(head));
    tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", t + i);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    printf("%lld\n", f[1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}