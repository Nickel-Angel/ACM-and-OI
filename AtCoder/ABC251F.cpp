/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], tot;
bool vis[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    vis[u] = true;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (vis[v])
            continue;
        printf("%d %d\n", u, v);
        dfs(v);
    }
}

void bfs()
{
    std::queue<int> q;
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    q.push(1);
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (vis[v])
                continue;
            printf("%d %d\n", u, v);
            vis[v] = true;
            q.push(v);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1);
    bfs();
    return 0;
}