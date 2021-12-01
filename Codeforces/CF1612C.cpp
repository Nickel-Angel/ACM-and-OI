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

long long k, x;

inline long long calc(long long x)
{
    return (1 + x) * x / 2;
}

inline void solve()
{
    scanf("%lld%lld", &k, &x);
    long long sum = calc(k);
    if (x <= sum)
    {
        int res = 0;
        for (int i = log2(k); i >= 0; --i)
        {
            res += (1 << i);
            if (res > k || calc(res) >= x)
                res -= (1 << i);
        }
        printf("%d\n", res + 1);
    }
    else
    {
        x -= calc(k - 1);
        int res = 0;
        for (int i = log2(k); i >= 0; --i)
        {
            res += (1 << i);
            if (res > k || sum - calc(res) < x)
                res -= (1 << i);
        }
        printf("%lld\n", 2 * k - 1 - res);
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