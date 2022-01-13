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

const int maxn = 1e5 + 10;
int n, c[600][600];

inline void solve()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= 2 * n; ++i)
    {
        for (int j = 1; j <= 2 * n; ++j)
        {
            scanf("%d", c[i] + j);
            if (i > n && j > n)
                sum += c[i][j];
        }
    }
    ll ans = 1e9;
    ans = min(ans, (ll)min(c[1][n + 1], c[1][2 * n]));
    ans = min(ans, (ll)min(c[n][n + 1], c[n][2 * n]));
    ans = min(ans, (ll)min(c[n + 1][1], c[2 * n][1]));
    ans = min(ans, (ll)min(c[n + 1][n], c[2 * n][n]));
    printf("%lld\n", ans + sum);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}