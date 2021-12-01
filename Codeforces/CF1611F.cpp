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

const int maxn = 2e5 + 10;
int n, s, a[maxn];
int q[maxn], l, r, L, R;

inline void solve()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    L = 1, R = 0;
    ll sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (L <= R && sum + s < 0)
        {
            sum -= a[q[L]];
            ++L;
        }
        if (sum + s >= 0 && ans < R - L + 1)
        {
            ans = R - L + 1;
            l = q[L], r = q[R];
        }
        q[++R] = i;
        sum += a[i];
    }
    if (sum + s >= 0 && ans < R - L + 1)
    {
        ans = R - L + 1;
        l = q[L], r = q[R];
    }
    if (!ans)
    {
        puts("-1");
        return;
    }
    printf("%d %d\n", l, r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}