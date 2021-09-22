/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, dp[maxn];
vector<int> e[maxn];

int dfs(int u)
{
    if (!dp[u])
        return dp[u] = 0x3f3f3f3f;        
    if (dp[u] != -1)
        return dp[u];
    dp[u] = 0;
    int res = 1;
    for (auto v : e[u])
        res = max(res, dfs(v) + (v > u));
    return dp[u] = res;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1, k; i <= n; ++i)
    {
        dp[i] = -1;
        scanf("%d", &k);
        e[i].clear();
        for (int j = 1, v; j <= k; ++j)
        {
            scanf("%d", &v);
            e[i].push_back(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dfs(i));
    printf("%d\n", (ans >= inf) ? -1 : ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}