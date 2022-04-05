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

const int maxn = 1e5 + 10;
int n, x, a[maxn];

inline void solve()
{
    scanf("%d%d", &n, &x);
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ans += (a[i] + x - 1) / x;
        sum += a[i];
    }
    printf("%lld %lld\n", (sum + x - 1) / x, ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}