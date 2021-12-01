/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 2e5 + 10;
int n, root, par[maxn], w[maxn], dis[maxn], p[maxn], rank[maxn];
vector<int> e[maxn];

bool dfs(int u)
{
    bool flag = true;
    for (int v : e[u])
        flag &= (rank[u] < rank[v]) & dfs(v);
    return flag;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", par + i);
        if (par[i] == i)
        {
            root = i;
            continue;
        }
        e[par[i]].push_back(i);
    }
    for (int i = 1, u; i <= n; ++i)
    {
        scanf("%d", &u);
        rank[u] = i, p[i] = u;
    }
    if (!dfs(root))
    {
        puts("-1");
        return;
    }
    memset(dis, 0, sizeof(dis));
    w[p[1]] = 0, dis[p[1]] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dis[p[i]] = dis[par[p[i]]];
        w[p[i]] = dis[p[i]] < dis[p[i - 1]] ? dis[p[i - 1]] - dis[p[i]] + 1 : 1;
        dis[p[i]] += w[p[i]]; 
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", w[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}