/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using std::vector;

typedef std::pair<long long, int> P;

const int maxn = 1e5 + 10;
bool vis[maxn];
int x, y, z;
long long h, dis[maxn];

vector<P> e[maxn];

inline void dijkstra(int S)
{
    std::priority_queue<P, vector<P>, std::greater<P> > q;
    q.push(P(0, S));
    dis[S] = 0;
    int u;
    while (!q.empty())
    {
        u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        for (int i = 0, v; i < e[u].size(); ++i)
        {
            v = e[u][i].first;
            if (vis[v])
                continue;
            if (dis[v] > dis[u] + e[u][i].second)
            {
                dis[v] = dis[u] + e[u][i].second;
                q.push(P(dis[v], v));
            }
        }
    }
}

int main()
{
    scanf("%lld%d%d%d", &h, &x, &y, &z);
    --h;
    for (int i = 0; i < x; ++i)
    {
        e[i].push_back(P((i + y) % x, y));
        e[i].push_back(P((i + z) % x, z));
        dis[i] = (1ull << 63) - 1;
    }
    dijkstra(0);
    long long ans = 0;
    for (int i = 0; i < x; ++i)
    {
        if (h >= dis[i])
            ans += (h - dis[i]) / x + 1;
    }
    printf("%lld\n", ans);
    return 0;
}