/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e5 + 10;
int n, a[maxn], cnt[40];

int main()
{
    scanf("%d", &n);
    long long ans = 0, res;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ans += a[i];
        for (int j = 0; j < 30; ++j)
        {
            if ((a[i] >> j) & 1)
                ++cnt[j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        res = 0;
        for (int j = 0; j < 30; ++j)
        {
            if ((a[i] >> j) & 1)
                res += (1ll << j) * (n - cnt[j]);
            else
                res += (1ll << j) * cnt[j];
        }
        ans = std::max(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}