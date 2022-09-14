/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

typedef long long ll;

const ll inf = 1e18;
int h, w, head[210], to[20410], next[20410], tot = 1;
int depth[210], cur[210], S, T;
ll a[110][110], R[110], C[110], val[20410];
std::queue<int> q;

inline void add_edge(int u, int v, ll w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

bool bfs()
{
    for (int i = 0; i <= h + w + 1; ++i)
    {
        cur[i] = head[i];
        depth[i] = -1;
    }
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
        flow = dfs(v, std::min(val[c], given - used));
        if (flow)
        {
            val[c] -= flow;
            val[c ^ 1] += flow;
            used += flow;
            if (used == given)
                break;
        }
        else
            depth[v] = -1;
    }
    return used;
}

inline ll maxflow()
{
    ll res = 0, curflow;
    while (bfs())
    {
        while (curflow = dfs(S, inf))
            res += curflow; 
    }
    return res;
}

int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            scanf("%lld", a[i] + j);
            R[i] += a[i][j], C[j] += a[i][j];
        }
    }
    S = 0, T = h + w + 1;
    ll ans = 0;
    for (int i = 1; i <= h; ++i)
    {   
        for (int j = 1; j <= w; ++j)
        {
            if (a[i][j] >= 0)
                add_edge(i, j + h, a[i][j]), add_edge(j + h, i, 0);
            else
                add_edge(i, j + h, inf), add_edge(j + h, i, 0);
        }
    }
    for (int i = 1; i <= h; ++i)
    {
        if (R[i] > 0)
        {
            add_edge(S, i, R[i]), add_edge(i, S, 0);
            ans += R[i];
        }
    }
    for (int i = 1; i <= w; ++i)
    {
        if (C[i] > 0)
        {
            add_edge(i + h, T, C[i]), add_edge(T, i + h, 0);
            ans += C[i];
        }
    }
    printf("%lld\n", ans - maxflow());
    return 0;
}