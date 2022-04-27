/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 2e5 + 10;
int n, w[maxn], par[maxn], deg[maxn];

inline void vartex_sort()
{
    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] == 1)
            q.push(i);
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        --deg[u], --deg[par[u]];
        if (deg[par[u]] == 1)
            q.push(par[u]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", par + i);
        ++deg[i], ++deg[par[i]];
    }
    vartex_sort();
    int ans = 0, cur;
    for (int i = 1, u, v; i <= n; ++i)
    {
        if (deg[i])
        {
            cur = 2e9;
            u = i, v = i;
            do
            {
                cur = std::min(cur, w[u]);
                deg[u] = 0;
                u = par[u], v = par[par[v]];
            } while (u != v);
            ans += cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}