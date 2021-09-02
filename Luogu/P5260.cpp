/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = (1 << 15) + 10;
const int maxm = 2e6 + 10;
int q, n, m, head[maxn], to[maxm], next[maxm], tot = 0, id[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline void solve()
{
    memset(head, 0, sizeof(head));
    memset(id, -1, sizeof(id));
    tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    if ((n & (n - 1)) != 0 || m != log2(n) * n / 2)
    {
        puts("-1");
        return;
    }
    id[0] = 0;
    std::queue<int> q;
    for (int c = head[0], i = 0, v; c; c = next[c], ++i)
    {
        v = to[c];
        q.push(v);
        id[v] = 1 << i;
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (id[v] != -1)
                continue;
            q.push(v);
            id[v] = 0;
            for (int j = head[v]; j; j = next[j])
            {
                if (id[to[j]] != -1)
                    id[v] |= id[to[j]];
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int c = head[i], v; c; c = next[c])
        {
            v = to[c];
            int cur = id[v] ^ id[i];
            if ((cur & (cur - 1)) != 0)
            {
                puts("-1");
                return;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d%c", id[i], " \n"[i == n - 1]);
}

int main()
{
    scanf("%d", &q);
    while (q--)
        solve();
    return 0;
}