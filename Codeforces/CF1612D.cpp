/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long ll;

using std::min;
using std::max;
using std::sort;
using std::swap;

long long a, b, x;

bool calc(ll a, ll b, ll x)
{
    if (a == x || b == x)
        return true;
    if (a < b)
        swap(a, b);
    if (a - b < b)
        b = a - b;
    if (max(a, b) < x || a == 0 || b == 0)
        return false;
    ll cnt = max(1ll, (a - max(b, x)) / (2 * b));
    return calc(a - cnt * b, b, x);
}

inline void solve()
{
    scanf("%lld%lld%lld", &a, &b, &x);
    puts(calc(a, b, x) ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}