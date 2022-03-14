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

const int maxn = 2e5 + 10;
int n;
ll a[maxn], b[maxn], ans[5];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", b + i);
    ll res = 0, val = 1e9; 
    for (int i = 1; i <= n; ++i)
        val = min(val, (ll)abs(a[1] - b[i]));
    ans[1] = val;
    res += val;
    val = 1e9;
    for (int i = 1; i <= n; ++i)
        val = min(val, (ll)abs(a[n] - b[i]));
    ans[2] = val;
    res += val;
    val = 1e9;
    for (int i = 1; i <= n; ++i)
        val = min(val, (ll)abs(b[1] - a[i]));
    ans[3] = val;
    res += val;
    val = 1e9;
    for (int i = 1; i <= n; ++i)
        val = min(val, (ll)abs(b[n] - a[i]));
    ans[4] = val;
    res += val;
    ll c = min(res, min((ll)abs(a[n] - b[n]) + abs(a[1] - b[1]), (ll)abs(a[n] - b[1]) + abs(b[n] - a[1])));
    c = min(c, abs(a[1] - b[1]) + ans[2] + ans[4]);
    c = min(c, abs(a[1] - b[n]) + ans[2] + ans[3]);
    c = min(c, abs(a[n] - b[1]) + ans[1] + ans[4]);
    c = min(c, abs(a[n] - b[n]) + ans[1] + ans[3]);
    printf("%lld\n", c);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}