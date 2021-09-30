/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;
using std::sort;
using std::lower_bound;

const int maxn = 2e5 + 10;
int n, m;
long long a[maxn];

int main()
{
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    scanf("%d", &m);
    long long x, y, ans;
    int pos;
    while (m--)
    {
        scanf("%lld%lld", &x, &y);
        pos = lower_bound(a + 1, a + n + 1, x) - a;
        ans = 2e18;
        if (pos > 1)
            ans = min(ans, x - a[pos - 1] + max(0ll, y - sum + a[pos - 1]));
        if (pos <= n)
            ans = min(ans, max(0ll, y - sum + a[pos]));
        printf("%lld\n", ans);
    }
    return 0;
}