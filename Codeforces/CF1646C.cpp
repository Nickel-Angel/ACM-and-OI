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

ll n, fac[20];

inline int popcount(ll x)
{
    int res = 0;
    while (x)
    {
        x -= (x & -x);
        ++res;
    }
    return res;
}

inline void solve()
{
    scanf("%lld", &n);
    int ans = popcount(n);
    for (int i = 0; i < (1 << 12); ++i)
    {
        ll x = 0;
        int cnt = 0;
        for (int j = 0; j < 12; ++j)
        {
            if (i & (1 << j))
            {
                x += fac[j + 3];
                ++cnt;
            }
        }
        if (x > n)
            continue;
        ans = min(ans, popcount(n - x) + cnt);
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    fac[0] = 1;
    for (int i = 1; i < 16; ++i)
        fac[i] = fac[i - 1] * i;
    while (t--)
        solve();
    return 0;
}