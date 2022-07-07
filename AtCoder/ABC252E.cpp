/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>

using std::pair;

typedef pair<long long, int> P;

const int maxn = 2e5 + 10;
int n, m, pre[maxn];
int head[maxn], to[maxn << 1], next[maxn << 1], val[maxn << 1], tot = 1;
long long dis[maxn];
bool vis[maxn];

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dijkstra(int S)
{
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    for (int i = 1; i <= n; ++i)
    {
        dis[i] = 1e14;
        vis[i] = false;
    }
    dis[S] = 0;
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
            if (dis[v] > dis[u] + val[c])
            {
                dis[v] = dis[u] + val[c];
                pre[v] = c / 2;
                q.push(P(dis[v], v));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w), add_edge(v, u, w);
    }
    dijkstra(1);
    for (int i = 2; i <= n; ++i)
        printf("%d%c", pre[i], " \n"[i == n]);
    return 0;
}