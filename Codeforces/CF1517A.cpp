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
    if (n % 2050 == 0)
    {
        ll x = n / 2050;
        int ans = 0;
        while (x)
        {
            ans += x % 10;
            x /= 10;
        }
        printf("%d\n", ans);
        return;
    }
    puts("-1");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}