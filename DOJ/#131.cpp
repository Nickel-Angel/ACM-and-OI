/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

typedef long long ll;

int n, a[2010];
ll sum[2020], ans[2020];

std::map<ll, int> cnt;

inline void calc(ll x)
{
    cnt.clear();
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        ++cnt[sum[i] % x];
        res = std::max(res, cnt[sum[i] % x]);
    }
    ans[res] = std::max(ans[res], x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; 1ll * i * i <= sum[n]; ++i)
    {
        if (sum[n] % i != 0)
            continue;
        calc(i), calc(sum[n] / i);
    }
    for (int i = n - 1; i > 0; --i)
        ans[i] = std::max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}