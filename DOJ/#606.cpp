/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, L[maxn], R[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", L + i, R + i);
    std::sort(L + 1, L + n + 1);
    std::sort(R + 1, R + n + 1);
    long long ans = n;
    for (int i = 1; i <= n; ++i)
        ans += std::max(L[i], R[i]);
    printf("%lld\n", ans);
    return 0;
}