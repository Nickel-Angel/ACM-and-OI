/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[2010];
long long f[2010][2010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
    {
        for (int l = 1, r = i; r <= n; ++l, ++r)
        {
            f[l][r] = std::min(f[l + 1][r], f[l][r - 1]) + a[r] - a[l];
        }
    }
    printf("%lld\n", f[1][n]);
    return 0;
}