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

const int maxn = 2e5 + 10;
int n, m, head[maxn], from[maxn], to[maxn], next[maxn], tot;
int dfn[maxn], low[maxn], dfs_t, s[maxn], top;
int size[maxn], color[maxn], cnt, ans, in[maxn];
bool ins[maxn], dp[maxn];
vector<int> e[maxn];

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    from[tot] = u;
    next[tot] = head[u];
    head[u] = tot;
}

void tarjan(int u)
{
    dfn[u] = ++dfs_t, low[u] = dfn[u];
    ins[u] = true, s[++top] = u;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        ++cnt;
        do
        {
            v = s[top];
            --top;
            ins[v] = false;
            color[v] = cnt;
            ++size[cnt];
        }while (u != v);
    }
}

inline void vartex_sort()
{
    std::queue<int> q;
    for (int i = 1; i <= cnt; ++i)
    {
        if (in[i] == 0)
            q.push(i);
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        dp[u] |= size[u] > 1;
        if (dp[u])
            ans += size[u];
        q.pop();
        for (int v : e[u])
        {
            --in[v];
            dp[v] |= dp[u];
            if (in[v] == 0)
                q.push(v);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (color[from[i]] == color[to[i]])
            continue;
        e[color[to[i]]].push_back(color[from[i]]);
        ++in[color[from[i]]];
    }
    vartex_sort();
    printf("%d\n", ans);
    return 0;
}