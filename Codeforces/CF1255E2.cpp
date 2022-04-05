/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, a[maxn];
long long sum[maxn];

inline long long calc(long long d)
{
    long long res = 0;
    for (int i = 1; i < n; ++i)
        res += std::min(sum[i] % d, d - sum[i] % d);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    long long tot = sum[n], ans = tot == 1 ? -1 : 1e18;
    for (int i = 2; 1ll * i * i <= tot; ++i)
    {
        if (tot % i == 0)
        {
            ans = std::min(ans, calc(i));
            while (tot % i == 0)
                tot /= i;
        }
    }
    if (tot > 1)
        ans = std::min(ans, calc(tot));
    printf("%lld\n", ans);
    return 0;
}