/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::swap;
using std::vector;

typedef long long ll;

const ll inf = 1e18;
char tools[10000];
int m, n, S, T, head[160], to[1010], next[1010], tot = 1;
int depth[160], cur[160];
ll val[1010];

inline void add_edge(int u, int v, ll w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

bool bfs()
{
    for (int i = 0; i <= T; ++i)
        depth[i] = -1, cur[i] = head[i];
    std::queue<int> q;
    q.push(S);
    depth[S] = 0;
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (val[c] && depth[v] == -1)
            {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    return depth[T] != -1;
}

ll dfs(int u, ll given)
{
    if (u == T)
        return given;
    ll used = 0, flow;
    for (int v, &c = cur[u]; c; c = next[c])
    {
        v = to[c];
        if (!val[c] || depth[v] != depth[u] + 1)
            continue;
        flow = dfs(v, min(val[c], given - used));
        if (flow)
        {
            val[c] -= flow, val[c ^ 1] += flow;
            used += flow;
            if (used == given)
                break;
        }
        else
            depth[v] = -1;
    }
    return used;
}

inline ll dinic()
{
    ll res = 0, flow;
    while (bfs())
    {
        while (flow = dfs(S, inf))
            res += flow;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    T = n + m + 1;
    ll ans = 0;
    for (int i = 1, p; i <= n; ++i)
    {
        scanf("%d", &p);
        ans += p;
        add_edge(S, i, p), add_edge(i, S, 0);
        memset(tools, 0, sizeof(tools));
        cin.getline(tools, 10000);
        int ulen = 0, tool;
        while (sscanf(tools + ulen, "%d", &tool) == 1)
        {
            add_edge(i, tool + n, inf), add_edge(tool + n, i, 0);
            if (tool == 0)
                ulen++;
            else
            {
                while (tool)
                {
                    tool /= 10;
                    ulen++;
                }
            }
            ulen++;
        }
    }
    for (int i = 1, c; i <= m; ++i)
    {
        scanf("%d", &c);
        add_edge(i + n, T, c), add_edge(T, i + n, 0);
    }
    ans = ans - dinic();
    for (int i = 1; i <= n; ++i)
    {
        if (depth[i] != -1)
            printf("%d ", i);
    }
    puts("");
    for (unsigned i = n + 1; i <= n + m; ++i)
    {
        if (depth[i] != -1)
            printf("%d ", i - n);
    }
    puts("");
    printf("%lld\n", ans);
    return 0;
}