/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::pair;

typedef pair<int, int> P;

const int maxn = 4e5 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], tot = 0, deg[maxn], ans;
bool vis[maxn];

inline void add_edge(int u, int v)
{   
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline void bfs()
{
    std::queue<P> q;
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] == 1)
            q.push(P(i, 1));
    }
    int u, step;
    while (!q.empty())
    {
        u = q.front().first, step = q.front().second;
        --ans, q.pop();
        vis[u] = true;
        if (step == m)
            continue;
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (vis[v])
                continue;
            --deg[v];
            if (deg[v] == 1)
                q.push(P(v, step + 1));
        }
    }
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        puts("0");
        return;
    }
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        ++deg[u], ++deg[v];
        add_edge(u, v), add_edge(v, u);
    }
    ans = n;
    bfs();
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}