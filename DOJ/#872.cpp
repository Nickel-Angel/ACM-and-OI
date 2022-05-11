/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <map>

const int maxn = 1e5 + 10;
int n, a[maxn];
long long sum[maxn];
std::map<long long, long long> cnt;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[n] % 3 != 0)
    {
        puts("0");
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (sum[i] == sum[n] / 3 * 2)
            ans += cnt[sum[n] / 3];
        ++cnt[sum[i]];
    }
    printf("%lld\n", ans);
    return 0;
}