/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn];
long long c[maxn], r[maxn];

inline long long calc(int x)
{
    return 1ll * x * (x - 1) * (x - 2) / 6;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        r[i] = 0, c[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a + i, b + i);
        ++r[a[i]], ++c[b[i]];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += (r[a[i]] - 1) * (c[b[i]] - 1);
    printf("%lld\n", calc(n) - ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}