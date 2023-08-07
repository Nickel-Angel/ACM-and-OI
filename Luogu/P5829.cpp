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

const int maxn = 1e6 + 10;
int n, m, par[maxn], head[maxn], to[maxn], next[maxn], tot;
int size[maxn], depth[maxn], son[maxn], top[maxn];
char s[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u)
{
    size[u] = 1, depth[u] = depth[par[u]] + 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs_son(v);
        size[u] += size[v];
        if (!son[u] || size[v] > size[son[u]])
            son[u] = v;
    }
    //printf("(%d\%d)\n", u, son[u]);
}

void dfs_top(int u, int anc)
{
    //printf("(%d %d)\n", u, anc);
    top[u] = anc;
    if (!son[u])
        return;
    dfs_top(son[u], anc);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == son[u])
            continue;
        dfs_top(v, v);
    }
}

inline int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        x = par[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    add_edge(0, 1);
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && s[j + 1] != s[i])
            j = par[j];
        if (s[j + 1] == s[i])
            ++j;
        par[i] = j;
        add_edge(par[i], i);
        //printf("(%d, %d)\n", par[i], i);
    }
    dfs_son(0), dfs_top(0, 0);
    scanf("%d", &m);
    int x, y, ans;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        ans = lca(x, y);
        if (ans == x)
            ans = par[x];
        if (ans == y)
            ans = par[y];
        printf("%d\n", ans);
    }
    return 0;
}