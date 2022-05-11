/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>

using std::pair;
using std::array;

typedef long long ll;
typedef pair<ll, int> P;

const int maxn = 2e5 + 10;
int k, n, m, head[maxn], from[maxn << 1], to[maxn << 1], next[maxn << 1], val[maxn << 1], tot;
int belong[maxn];
ll dis[maxn];
bool vis[maxn];
std::priority_queue<P, std::vector<P>, std::greater<P>> q;

class Union_Find_Set
{
  private:
    int par[maxn];

    int find(int x)
    {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

  public:
    inline void init(int n)
    {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }

    inline bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        par[x] = y;
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S;

inline void add_edge(int u, int v, int w)
{
    from[++tot] = u;
    to[tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= k; ++i)
    {
        belong[i] = i;
        dis[i] = 0;
        q.push({0, i});
    }
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
                belong[v] = belong[u];
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w), add_edge(v, u, w);
    }
    dijkstra();
    std::vector<array<ll, 3>> path; 
    for (int c = 1; c <= 2 * m; c += 2)
    {
        if (belong[from[c]] == belong[to[c]])
            continue;
        path.push_back({dis[from[c]] + dis[to[c]] + val[c], belong[from[c]], belong[to[c]]});
    }
    std::sort(path.begin(), path.end());
    unsigned cur = 0;
    int x, y, q;
    ll t;
    S.init(k);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%lld", &x, &y, &t);
        while (cur < path.size() && path[cur][0] <= t)
        {
            S.unite(path[cur][1], path[cur][2]);
            ++cur;
        }
        puts(S.judge(x, y) ? "Yes" : "No");
    }
    return 0;
}