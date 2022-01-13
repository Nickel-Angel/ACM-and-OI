/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, h[310];

int main()
{
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", h + i);
    std::sort(h + 1, h + n + 1);
    ans += h[n] * h[n];
    int l = 1, r = n;
    while (l < r)
    {
        //printf("%d %d\n", l, r);
        ans += (h[l] - h[r]) * (h[l] - h[r]);
        --r;
        if (l == r)
            break;
        //printf("%d %d\n", l, r);
        ans += (h[l] - h[r]) * (h[l] - h[r]);
        ++l;
    }
    printf("%lld\n", ans);
    return 0;
}