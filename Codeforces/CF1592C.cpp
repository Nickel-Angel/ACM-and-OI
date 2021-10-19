/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, k, a[maxn], f[maxn], sum;
int head[maxn], to[maxn << 1], next[maxn << 1], tot, cnt;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    f[u] = a[u];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        if (f[v] == sum)
            ++cnt;
        else
            f[u] ^= f[v];
    }
}

inline void solve()
{
    scanf("%d%d", &n, &k);
    sum = 0, tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        head[i] = 0, sum ^= a[i];
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    //printf("sum %d\n", sum);
    if (!sum)
    {
        puts("YES");
        return;
    }
    if (k == 2)
    {
        puts("NO");
        return;
    }
    cnt = 0;
    dfs(1, 0);
    puts(cnt >= 2 ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}