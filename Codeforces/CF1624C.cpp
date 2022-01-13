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

int n, a[60], match[120];
vector<int> e[120];
bool vis[60];

bool dfs(int u)
{
    for (int v : e[u])
    {
        if (vis[v])
            continue;
        vis[v] = true;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i <= n; ++i)
    {
        match[i] = 0;
        scanf("%d", a + i);
        while (a[i] > n)
            a[i] /= 2;
        while (a[i])
        {
            e[i].push_back(a[i]);
            a[i] /= 2;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, false, sizeof(vis));
        if (dfs(i))
            ++cnt;
    }
    puts(cnt == n ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}