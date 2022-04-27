/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, m, cnt1, cnt2, head[maxn << 1], to[maxn << 2], next[maxn << 2], tot;
bool vis[maxn << 1];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline void bonus_add(int u, int v)
{
    add_edge(u, v), add_edge(v, u);
}

void dfs(int u)
{
    vis[u] = true;
    cnt1 += (u <= m), cnt2 += (u > m);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        bonus_add(i, x + m), bonus_add(i, y + m);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (vis[i])
            continue;
        cnt1 = 0, cnt2 = 0;
        dfs(i);
        ans += std::max(0, cnt1 - cnt2 + 1);
    }
    printf("%d\n", ans);
    return 0;
}