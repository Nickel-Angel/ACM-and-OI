/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a, d;

inline void solve()
{
    scanf("%d%d%d", &n, &a, &d);
    long long x = n;
    while (d && d % 2 == 0)
    {
        d /= 2;
        x += x - 1;
    }
    printf("%lld\n", x - n);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}