/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

int n;
ll a[110];

ll gcd(ll x, ll y)
{
    return y ? gcd(y, x % y) : x;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    ll g = a[1];
    for (int i = 3; i <= n; i += 2)
        g = gcd(g, a[i]);
    bool flag = false;
    for (int i = 2; i <= n; i += 2)
    {
        if (a[i] % g == 0)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        printf("%lld\n", g);
        return;
    }
    g = a[2];
    for (int i = 4; i <= n; i += 2)
        g = gcd(g, a[i]);
    flag = false;
    for (int i = 1; i <= n; i += 2)
    {
        if (a[i] % g == 0)
        {
           flag = true;
           break; 
        }
    }
    printf("%lld\n", flag ? 0 : g);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}