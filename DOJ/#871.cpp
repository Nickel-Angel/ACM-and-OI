/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

long long a, m;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

inline long long phi(long long x)
{
    long long res = x;
    for (int i = 2; 1ll * i * i <= x; ++i)
    {
        if (x % i != 0)
            continue;
        while (x % i == 0)
            x /= i;
        res = res / i * (i - 1);
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

inline void solve()
{
    scanf("%lld%lld", &a, &m);
    long long d = gcd(a, m);
    printf("%lld\n", phi(m / d));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}