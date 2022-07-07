/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

long long n;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

inline void solve()
{
    scanf("%lld", &n);
    long long ans = n / 2;
    while (gcd(ans, n) != 1)
        --ans;
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}