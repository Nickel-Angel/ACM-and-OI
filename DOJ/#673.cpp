/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

long long n, m;

inline long long calc(long long x)
{
    return x * (x + 1) / 2;
}

inline void solve()
{
    scanf("%lld%lld", &n, &m);
    printf("%lld\n", calc(n) - (n - m) % (m + 1) * calc((n - m) / (m + 1) + 1) - (m + 1 - (n - m) % (m + 1)) * calc((n - m) / (m + 1)));
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
        solve();
    return 0;
}