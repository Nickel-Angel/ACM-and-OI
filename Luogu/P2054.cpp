/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

ll n, m, l;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

inline ll mul(ll a, ll b, ll p)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

inline ll power(ll a, ll b, ll p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &l);
    ll x, y;
    exgcd(2, n + 1, x, y);
    x = (x % (n + 1) + n + 1) % (n + 1);
    printf("%lld\n", mul(l, power(x, m, n + 1), n + 1));
    return 0;
}