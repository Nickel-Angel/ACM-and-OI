/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 2e5 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], tot = 0;
int dis[maxn], f[maxn], deg[maxn];
bool key[maxn], lock[maxn];

inline void add_edge(int u, int v)
{
    ++deg[v];
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    //lock[u] = false;
    dis[u] = dis[pre] + 1;
    f[u] = key[u] ? 0 : 0x3f3f3f3f;
    bool flag = true;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        f[u] = min(f[u], f[v] + 1);
        flag &= lock[v];
    }
    //printf("%d %d %d %d %d ", u, dis[u] - 1, f[u], key[u] ? 1 : 0, deg[u]);
    if (deg[u] == 1 && u != 1)
        lock[u] = key[u];
    else
        lock[u] = (dis[u] - 1 >= f[u]) | flag;
    //printf("%d \n", lock[u] ? 1 : 0);
}

inline void solve()
{
    memset(head, 0, sizeof(head));
    memset(key, false, sizeof(key));
    memset(deg, 0, sizeof(deg));
    scanf("%d%d", &n, &m);
    for (int i = 1, u; i <= m; ++i)
    {
        scanf("%d", &u);
        key[u] = true;
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dis[1] = 0;
    dfs(1, 0);
    puts(lock[1] ? "NO" : "YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}