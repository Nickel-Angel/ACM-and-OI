/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using std::pair;
using std::vector;
using std::priority_queue;
using std::greater;
using std::min;

typedef pair<int, int> P;

const int maxn = 1e5 + 10;
int n, m, k, head[maxn], to[maxn << 1], next[maxn << 1], val[maxn << 1], tot;
int dis[20][maxn], a[20], p[20], rev[20];
double t, r, f[20][(1 << 20) + 10];
bool vis[maxn], lock[20][(1 << 20) + 10];

priority_queue<P, vector<P>, greater<P>> q;

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

inline void dijkstra(int S, int id)
{
    memset(dis[id], 0x3f, sizeof(dis[id]));
    memset(vis, false, sizeof(vis));
    dis[id][S] = 0;
    q.push(P(0, S));
    int u;
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (dis[id][v] > dis[id][u] + val[c])
            {
                dis[id][v] = dis[id][u] + val[c];
                q.push(P(dis[id][v], v));
            }
        }
    }
}

double dfs(int u, int S)
{
    if (lock[u][S])
        return f[u][S];
    lock[u][S] = true;
    double res = p[u] / 100.0 * dis[u][n] / t;
    for (int v = 1; v <= k; ++v)
    {
        if ((S >> (v - 1)) & 1)
            continue;
        res = min(res, p[u] / 100.0 * (dis[u][a[v]] / t + dfs(v, S | (1 << (v - 1)))));
    }
    f[u][S] = res + (100 - p[u]) / 100.0 * dis[u][n] / r;
    return f[u][S];
}

int main()
{
    scanf("%lf%lf%d%d", &t, &r, &n, &m);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w), add_edge(v, u, w);
    }
    scanf("%d", &k);
    int key = k + 1;
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d", a + i, p + i);
        if (a[i] == 1)
            key = i;
        dijkstra(a[i], i);
    }
    if (key == k + 1)
    {
        a[++k] = 1, p[k] = 100;
        dijkstra(a[k], k);
    }
    if (dis[key][n] == 0x3f3f3f3f)
    {
        puts("-1");
        return 0;
    }
    printf("%lf\n", dfs(key, 0));
    return 0;
}