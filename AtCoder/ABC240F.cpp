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

int n, m;

inline void solve()
{
    scanf("%d%d", &n, &m);
    ll ans, sum = 0, pre = 0, x, y, z;
    scanf("%lld%lld", &x, &y);
    sum += pre * y + x * (y + 1) * y / 2;
    pre += x * y;
    if (x < 0)
        ans = x;
    else
        ans = sum;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%lld%lld", &x, &y);
        if (x < 0 && pre > 0)
        {
            z = min(pre / -x, y);
            ans = max(ans, sum + pre * z + x * (z + 1) * z / 2);
        }
        sum += pre * y + x * (y + 1) * y / 2;
        pre += x * y; 
        ans = max(ans, sum);
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}