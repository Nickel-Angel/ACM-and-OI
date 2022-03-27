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

int n, b, x, y;

inline void solve()
{
    scanf("%d%d%d%d", &n, &b, &x, &y);
    ll ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cur + x > b)
        {
            cur -= y;
            ans += cur;
        }
        else
        {
            cur += x;
            ans += cur;
        }
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