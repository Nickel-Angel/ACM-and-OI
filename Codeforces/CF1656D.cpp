/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

ll n;

inline void solve()
{
    scanf("%lld", &n);
    if (n & 1)
    {
        puts("2");
        return;
    }
    ll x = n;
    int k = 0;
    while (x % 2 == 0)
    {
        ++k;
        x /= 2;
    }
    if (x == 1)
    {
        puts("-1");
        return;
    }
    if (k < 31 && (1ll << (2 * k + 1)) + (1ll << k) <= n)
    {
        printf("%lld\n", 1ll << (k + 1));
        return;
    }
    printf("%lld\n", x);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}