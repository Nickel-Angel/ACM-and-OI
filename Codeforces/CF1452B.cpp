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

const int maxn = 1e5 + 10;
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    ll sum = 0;
    int bound = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum += a[i];
        bound = max(bound, a[i]);
    }
    ll ans;
    if (1ll * (n - 1) * bound >= sum)
        ans = 1ll * (n - 1) * bound - sum;
    else
        ans = (sum + n - 2) / (n - 1) * (n - 1) - sum;
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