/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e6 + 10;
int n, A, cnt[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        A = std::max(A, x);
        ++cnt[x];
    }
    long long ans = 0;
    for (int i = 1, d; i <= A; ++i)
    {
        for (int j = 1; i * j <= A; ++j)
        {
            d = std::max(i, j) - std::min(i, j);
            if (d % 2 == 0)
                ans += 1ll * cnt[i * j] * cnt[d / 2];
        }
    }
    printf("%lld\n", ans / 2);
    return 0;
}