/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e6 + 10;
int n, par[maxn], depth[maxn], maxd[maxn], pre, d;
long long ans;
std::vector<int> e[maxn];

void dfs_init(int u)
{
    maxd[u] = depth[u];
    for (int v : e[u])
    {
        dfs_init(v);
        maxd[u] = std::max(maxd[u], maxd[v]);
    }
    std::sort(e[u].begin(), e[u].end(), [&](int x, int y){return maxd[x] < maxd[y];});
}

void dfs_solve(int u)
{
    if (e[u].empty())
    {
        if (!pre)
            ans += depth[u];
        else
            ans += std::min(depth[u], d);
        pre = u, d = 0;
        return;
    }
    for (int v : e[u])
    {
        ++d;
        dfs_solve(v);
        ++d;
    }
}

inline void solve(int t)
{
    scanf("%d", &n);
    depth[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", par + i);
        depth[i] = depth[par[i]] + 1;
        e[par[i]].push_back(i);
    }
    dfs_init(1);
    ans = 0, pre = 0, d = 0;
    dfs_solve(1);
    printf("Case #%d: %lld\n", t, ans);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve(i);
    return 0;
}