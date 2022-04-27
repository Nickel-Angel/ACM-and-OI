/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e5 + 10;
int q, len, head[maxn << 1], next[maxn << 1], to[maxn << 1], tot;
int a[maxn], color[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int cur)
{
    if (u <= len)
    {
        a[u] = cur;
        return;
    }
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v, cur);
    }
}

int main()
{
    scanf("%d", &q);
    int opt, x, y, cnt = q, m = 0;
    while (q--)
    {
        scanf("%d%d", &opt, &x);
        if (opt == 1)
        {
            ++len;
            if (!color[x])
                color[x] = ++cnt;
            add_edge(color[x], len);
            m = std::max(m, x);
        }
        else
        {
            scanf("%d", &y);
            if (x == y || !color[x])
                continue;
            m = std::max({m, x, y});
            if (!color[y])
                color[y] = ++cnt;
            add_edge(color[y], color[x]);
            color[x] = 0;
        }
    }
    for (int i = 1; i <= m; ++i)
        dfs(color[i], i);
    for (int i = 1; i <= len; ++i)
        printf("%d%c", a[i], " \n"[i == len]);
    return 0;
}