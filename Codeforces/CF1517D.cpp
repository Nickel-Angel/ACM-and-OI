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

const int maxn = 2500005 + 250000;
int n, m, level;
int head[maxn], to[maxn << 2], next[maxn << 2], val[maxn << 2], tot = 0;
int dis[maxn];
bool vis[maxn];

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}   

int id(int i, int j, int k)
{
    return n * m * (k - 1) + m * (i - 1) + j;
}

void bfs()
{
    std::queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            q.push(id(i, j, 1));
            dis[id(i, j, 1)] = 0;
            vis[id(i, j, 1)] = true;
        }
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            dis[v] = min(dis[v], dis[u] + val[c]);
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &level);
    for (int i = 1, x; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            scanf("%d", &x);
            for (int k = 1; k <= level / 2; ++k)
            {
                add_edge(id(i, j, k), id(i, j + 1, k + 1), x);
                add_edge(id(i, j + 1, k), id(i, j, k + 1), x);
            }
        }   
    }
    for (int i = 1, x; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &x);
            for (int k = 1; k <= level / 2; ++k)
            {
                add_edge(id(i, j, k), id(i + 1, j, k + 1), x);
                add_edge(id(i + 1, j, k), id(i, j, k + 1), x);
            }
        }
    }
    if (level & 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                printf("-1%c", " \n"[j == m]);
            }
        }
        return 0;
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {   
            printf("%d%c", dis[id(i, j, level / 2 + 1)] * 2, " \n"[j == m]);
        }
    }
    return 0;
}