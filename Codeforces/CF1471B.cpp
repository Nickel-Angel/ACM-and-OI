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

const int maxn = 5e6 + 10;
int n, x, a[maxn];
long long mul[maxn];

inline void solve()
{
    scanf("%d%d", &n, &x);
    ll ans = 0;
    memset(mul, 0, sizeof(mul));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        mul[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x == 0 && a[i] / x != 0)
        {
            a[++n] = a[i] / x;
            mul[n] = mul[i] * x;
        }
        else
            break;
    }
    for (int i = 1; i <= n; ++i)
        ans += a[i] * mul[i];
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