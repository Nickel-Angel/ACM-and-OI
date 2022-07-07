/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn], d[maxn];

inline void solve()
{
    scanf("%d", &n);
    long long x = 0, cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        d[i] = a[i] - a[i - 1];
        if (i > 1)
        {
            cur += abs(d[i]);
            if (d[i] < 0)
                x += d[i];
        }
    }
    printf("%lld\n", llabs(d[1] + x) + cur);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}