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
int dis[maxn], par[maxn], top, bottom, maxlen, para[maxn], f[maxn][21], g[maxn][21]; 
bool key[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre, int &farest)
{
    par[u] = pre;
    dis[u] = dis[pre] + 1;
    if (dis[u] > maxlen)
    {
        farest = u;
        maxlen = dis[u];
    }
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u, farest);
    }
}

void dfs_solve(int u, int pre, int jump[maxn][21])
{
    jump[u][0] = pre;
    for (int i = 1; jump[u][i - 1]; ++i)
        jump[u][i] = jump[jump[u][i - 1]][i - 1];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs_solve(v, u, jump);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0, top);
    maxlen = 0;
    dfs(top, 0, bottom);
    dfs_solve(top, 0, f), dfs_solve(bottom, 0, g);
    //printf("%d %d\n", top, bottom);
    int q, u, v, k;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &u, &k);
        v = u;
        for (int i = 21; i >= 0; --i)
        {
            if ((k >> i) & 1)
                v = f[v][i];
        }
        if (v)
        {
            printf("%d\n", v);
            continue;
        }
        v = u;
        for (int i = 21; i >= 0; --i)
        {
            if ((k >> i) & 1)
                v = g[v][i];
        }
        printf("%d\n", v ? v : -1);
    }
    return 0;
}