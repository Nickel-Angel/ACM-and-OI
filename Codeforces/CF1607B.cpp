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

long long x, n;

inline void solve()
{
    scanf("%lld%lld", &x, &n);
    if (x & 1)
    {
        if (n & 1)
            printf("%lld\n", (n - 1) / 2 % 2 ? x - 1 - n : x + n);
        else
            printf("%lld\n", n / 2 % 2 ? x - 1 : x);
    }
    else
    {
        if (n & 1)
        {
            printf("%lld\n", (n - 1) / 2 % 2 ? x + n + 1 : x - n);
        }
        else
        {
            printf("%lld\n", n / 2 % 2 ? x + 1 : x);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();    
    return 0;
}