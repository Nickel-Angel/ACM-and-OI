/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cassert>
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

ll a, s, non[70];
int n;

inline ll calc(ll x)
{
    ll res = 0;
    for (int i = 0; i <= n; ++i)
    {
        if ((x >> i) & 1)
            res |= non[i];
    }
    return res;
}

inline void solve()
{
    scanf("%lld%lld", &a, &s);
    s -= 2 * a, n = -1;
    for (int i = 0; i < 60; ++i)
    {
        if ((a >> i) & 1)
            continue;
        non[++n] = (1ll << i);
    }
    ll l = 0, r = (1ll << (n + 1)) - 1, mid;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (calc(mid) > s)
            r = mid - 1;
        else
            l = mid;
    }
    puts(calc(l) == s ? "Yes" : "No");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}