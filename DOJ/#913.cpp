/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

ll m, d, w;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int t;
    scanf("%d", &t);
    ll ans, a, tot;
    while (t--)
    {
        scanf("%lld%lld%lld", &m, &d, &w);
        if (d == 1)
        {
            printf("%lld\n", std::min(m, d) * (std::min(m, d) - 1) / 2);
            continue;
        }
        a = w / gcd(d - 1, w);
        tot = std::min(m, d) / a;
        //printf("%lld\n", a);
        ans = std::min(m, d) * tot - a * (1 + tot) * tot / 2;
        printf("%lld\n", ans);
    }
    return 0;
}