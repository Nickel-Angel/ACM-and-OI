/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

const int maxn = 1e5 + 10;
int n, b;

struct bale
{
    long long p, s;

    bale(int p = 0, int s = 0) : p(p), s(s) {}

    bool operator < (const bale &rhs) const
    {
        return p < rhs.p;
    }
}a[maxn];

int main()
{
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &a[i].s, &a[i].p);
    std::sort(a + 1, a + n + 1);
    int pos = std::upper_bound(a + 1, a + n + 1, bale(b, 0)) - a - 1;
    int l = pos, r = pos + 1;
    long long ans = 1e14;
    while (l > 0 && r <= n)
    {
        if (a[r].p - a[l].p <= min(a[r].s, a[l].s))
        {
            puts("0");
            return 0;
        }
        if (a[r].p - a[l].p > a[l].s)
        {
            --l;
        }
        else
        {
            ans = min(ans, a[r].p - a[l].p - a[r].s);
            ++r;
        }
    }
    l = pos, r = pos + 1;
    while (l > 0 && r <= n)
    {
        if (a[r].p - a[l].p <= min(a[r].s, a[l].s))
        {
            puts("0");
            return 0;
        }
        if (a[r].p - a[l].p > a[r].s)
        {
            ++r;
        }
        else
        {
            ans = min(ans, a[r].p - a[l].p - a[l].s);
            --l;
        }
    }
    printf("%lld\n", ans == 1e14 ? -1 : ans);
    return 0;
}