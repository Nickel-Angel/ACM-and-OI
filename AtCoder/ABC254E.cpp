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
typedef pair<int, int> P;

const int maxn = 1.5e5 + 10;
int n, m, Q, vis[maxn], head[maxn], to[maxn * 3], next[maxn * 3], tot;
ll sum[maxn][4];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void bfs(int S)
{
    std::queue<P> q;
    q.push(P(S, 0));
    int u, d;
    while (!q.empty())
    {
        u = q.front().first, d = q.front().second;
        q.pop();
        if (vis[u] == S)
            continue;
        //printf("%d %d %d\n", S, u, d);
        vis[u] = S;
        sum[S][d] += u;
        if (d == 3)
            continue;
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            q.push(P(v, d + 1));
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
    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
        for (int j = 1; j < 4; ++j)
            sum[i][j] += sum[i][j - 1];
    }
    scanf("%d", &Q);
    int x, k;
    while (Q--)
    {
        scanf("%d%d", &x, &k);
        printf("%lld\n", sum[x][k]);
    }    
    return 0;
}