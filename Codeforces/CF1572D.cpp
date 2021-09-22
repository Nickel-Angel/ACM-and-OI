/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>

using std::min;
using std::max;

const int maxn = 9010;
const int maxm = 200010;

int n, k, p[1 << 20], a[1 << 20], id[1 << 20], cnt = 0;
int head[maxn], to[maxm << 1], next[maxm << 1], tot = -1;
int val[maxm << 1], cost[maxm << 1], dis[maxn], maxflow = 0, maxcost = 0;
bool vis[maxn], key[1 << 20];

inline int popcount(int x)
{
    int res = 0;
    while (x)
    {
        x &= x - 1;
        ++res;
    }
    return res;
}

inline void add_edge(int u, int v, int w, int c)
{
    to[++tot] = v;
    val[tot] = w, cost[tot] = c;
    next[tot] = head[u];
    head[u] = tot;
}

inline bool spfa(const int &S, const int &T)
{
    std::queue<int> q;
    memset(dis, ~0x3f, sizeof(dis));
    q.push(S), dis[S] = 0;
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = false;
        for (int c = head[u], v; ~c; c = next[c])
        {
            v = to[c];
            if (val[c] && dis[v] < dis[u] + cost[c])
            {
                dis[v] = dis[u] + cost[c];
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dis[T] > -0x3f3f3f3f;
}

int dfs(int u, int flow, const int &T)
{
    if (u == T)
        return flow;
    vis[u] = true;
    int used = 0, cur;
    for (int c = head[u], v; ~c; c = next[c])
    {
        v = to[c];
        if (val[c] && dis[v] == dis[u] + cost[c] && !vis[v])
        {
            cur = dfs(v, min(flow - used, val[c]), T);
            maxcost += cur * cost[c];
            val[c] -= cur;
            val[c ^ 1] += cur;
            used += cur;
            if (used == flow)
                break;
        }
    }
    vis[u] = false;
    if (!used)
        dis[u] = 0x3f3f3f3f;
    return used;
}

inline void Dinic(int S, int T)
{
    maxflow = 0, maxcost = 0;
    while (spfa(S, T))
        maxflow += dfs(S, 0x3f3f3f3f, T);
}

int main()
{
    scanf("%d%d", &n, &k);
    k = min(k, 1 << (n - 1));
    for (int i = 0; i < (1 << n); ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
            p[j] = j;
        std::nth_element(p, p + 2 * k, p + (1 << n), [&](int x, int y){return a[x] + a[x ^ (1 << i)] > a[y] + a[y ^ (1 << i)];});
        for (int j = 0; j < 2 * k; ++j)
            key[p[j]] = true;
    }
    for (int i = 0; i < (1 << n); ++i)
    {
        if (key[i])
            id[i] = ++cnt;
    }
    int S = cnt + 2, T = cnt + 3;
    memset(head, -1, sizeof(head));
    add_edge(S, cnt + 1, k, 0), add_edge(cnt + 1, S, 0, 0);
    for (int i = 0; i < (1 << n); ++i)
    {
        if (!key[i])
            continue;
        if (popcount(i) & 1)
        {
            add_edge(id[i], T, 1, a[i]);
            add_edge(T, id[i], 0, -a[i]);
        }
        else
        {
            add_edge(cnt + 1, id[i], 1, a[i]);
            add_edge(id[i], cnt + 1, 0, -a[i]);
        }
    }
    for (int i = 0; i < (1 << n); ++i)
    {
        if (!(key[i]) || (popcount(i) & 1))
            continue;
        for (int j = 0; j < n; ++j)
        {
            if (!key[i ^ (1 << j)])
                continue;
            add_edge(id[i], id[i ^ (1 << j)], 1, 0);
            add_edge(id[i ^ (1 << j)], id[i], 0, 0);
        }
    }
    Dinic(S, T);
    printf("%d\n", maxcost);
    return 0;
}