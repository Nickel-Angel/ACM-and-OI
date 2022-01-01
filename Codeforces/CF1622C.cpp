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
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, a[maxn];
ll k, sum[maxn];

inline void solve()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    ll ans = 1e14, t;
    for (int i = 1; i <= n; ++i)
    {
        t = sum[i] + 1ll * (n - i) * a[1] - k;
        ans = min(ans, t <= 0 ? n - i : (t + n - i) / (n - i + 1) + n - i);
    }
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