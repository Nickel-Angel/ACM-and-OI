/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e7 + 10;
int x, y, k;

inline int count(int n) 
{
    int cnt = 0;
    for (int i = 2; i <= n / i; i++) 
    {
        if (n % i == 0)
        {
            ++cnt;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ++cnt;
    return cnt;
}

inline long long calc(int a)
{
    if ((a + y) % x)
        return 0;
    return 1ll << count((a + y) / x);
}

inline void solve()
{
    scanf("%d%d%d", &x, &y, &k);
    long long ans = 0;
    for (int i = 1; i <= k / i; ++i)
    {
        if (k % i == 0)
        {
            ans += calc(i);
            if (k / i != i)
                ans += calc(k / i);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    Euler(1e7);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}