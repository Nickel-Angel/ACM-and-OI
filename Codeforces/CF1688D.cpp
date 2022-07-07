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
int n, k, a[maxn];
ll sum[maxn];

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    if (k <= n)
    {
        ll ans = 0;
        for (int i = k; i <= n; ++i)
            ans = max(ans, sum[i] - sum[i - k]);
        ans += 1ll * k * (k - 1) / 2;
        printf("%lld\n", ans);
        return;
    }
    ll ans = sum[n] + 1ll * n * (k - n + k - 1) / 2;
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}