/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <cstdio>
#include <cstring>

long long n;

inline void solve()
{
    scanf("%lld", &n);
    printf("%lld %lld\n", -n + 1, n);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}