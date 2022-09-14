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
using std::queue;

typedef long long ll;

const int maxn = 3e5 + 10;
int S, T, m, head[maxn + 3000], to[maxn << 1], next[maxn << 1], tot;
int pre[maxn + 3000];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void bfs(int s)
{
    queue<int> q;
    for (int c = head[s], v; c; c = next[c])
    {
        v = to[c];
        q.push(v);
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (v == s)
                continue;
            if (pre[v])
            {
                printf("%d %d %d %d\n", s, pre[v], v, u);
                exit(0);
            }
            else
                pre[v] = u;
        }
    }
    for (int i = S + 1; i <= T; ++i)
        pre[i] = 0;
}

int main()
{
    scanf("%d%d%d", &S, &T, &m);
    T += S;
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = S + 1; i <= T; ++i)
        bfs(i);
    puts("-1");
    return 0;
}