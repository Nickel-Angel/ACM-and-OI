/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 2e4 + 10;
const int maxm = 2e5 + 10;
int n, m, head[maxn], to[maxm], next[maxm], tot = 0;
int dfn[maxn], low[maxn], timer = 0;
bool cut[maxn];
std::vector<int> ans;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void tarjan(int u, int pre)
{
    dfn[u] = ++timer;
    low[u] = dfn[u];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u])
                cut[u] = true;
        }
        else
            low[u] = std::min(low[u], dfn[v]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1, cnt; i <= n; ++i)
    {
        if (!dfn[i])
        {
            cnt = 0, dfn[i] = ++timer;
            for (int c = head[i], v; c; c = next[c])
            {
                v = to[c];
                if (!dfn[v])
                {
                    tarjan(v, i);
                    ++cnt;
                }
            }
            if (cnt > 1)
                cut[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (cut[i])
            ans.push_back(i);
    printf("%u\n", ans.size());
    for (auto c : ans)
        printf("%d ", c);
    return 0;
}