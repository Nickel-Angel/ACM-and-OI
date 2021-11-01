/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

inline void solve()
{
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (y % x == 0)
    {
        printf("%lld\n", x);
        return;
    }
    if (x >= y)
    {
        printf("%lld\n", x + y);
        return;
    }
    printf("%lld\n", y - (y % x) / 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}