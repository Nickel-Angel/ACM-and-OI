/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, size[maxn], head[maxn], to[maxn << 1], next[maxn << 1], tot;
long long ans = 0;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        ans += 1ll * size[u] * size[v] * (n - 1 - size[u] - size[v]);
        size[u] += size[v];
    }
    ++size[u];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d%*d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}