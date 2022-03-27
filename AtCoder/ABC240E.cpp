/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, head[maxn], to[maxn << 1], next[maxn << 1], tot;
int size[maxn], L[maxn], R[maxn], cnt;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    size[u] = 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        size[u] += size[v];
        L[u] = std::min(L[u], L[v]);
        R[u] = std::max(R[u], R[v]);
    }
    if (size[u] == 1)
    {
        ++cnt;
        L[u] = cnt, R[u] = cnt;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
        L[i] = n;
    }
    L[n] = n;
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", L[i], R[i]);
    return 0;
}