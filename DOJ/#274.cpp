/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;

const int maxn = 1e5 + 10;
int n, p, par[maxn];
int f[maxn], g[maxn], ans[maxn], id[maxn];
vector<int> e[maxn], pre[maxn], suf[maxn];

inline int calc(int u, int x)
{
    if (x == 0)
        return suf[u].size() > 1 ? suf[u][1] : 1;
    if (x == pre[u].size() - 1)
        return pre[u].size() > 1 ? pre[u][pre[u].size() - 2] : 1;
    return 1ll * pre[u][x - 1] * suf[u][x + 1] % p; 
}

void dfs_init(int u)
{
    f[u] = 1;
    for (int v : e[u])
    {
        dfs_init(v);
        f[u] = 1ll * f[u] * (1 + f[v]) % p;
    }
    if (e[u].size())
    {
        pre[u][0] = f[e[u][0]] + 1;
        for (unsigned i = 1; i < pre[u].size(); ++i)
            pre[u][i] = 1ll * pre[u][i - 1] * (f[e[u][i]] + 1) % p;
        suf[u].back() = f[e[u].back()] + 1;
        for (unsigned i = suf[u].size() - 1; i > 0; --i)
            suf[u][i - 1] = 1ll * suf[u][i] * (f[e[u][i - 1]] + 1) % p;
    }
}

void dfs_solve(int u)
{
    ans[u] = 1ll * f[u] * (g[u] + 1) % p;
    for (int v : e[u])
    {
        g[v] = 1ll * calc(u, id[v]) * (g[u] + 1) % p;
        dfs_solve(v);
    }
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        e[par[i]].push_back(i), id[i] = e[par[i]].size() - 1;
        pre[par[i]].push_back(0), suf[par[i]].push_back(0);
    }
    dfs_init(1), dfs_solve(1);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}