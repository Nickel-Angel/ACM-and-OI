/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

const ll p = 998244353;
const int maxn = 1e7 + 10;
int x, y, z, n;
ll fac[maxn], inv[maxn], inv_fac[maxn];

inline ll C(int a, int b)
{
    if (a < b || b < 0)
        return 0;
    return fac[a] * inv_fac[b] % p * inv_fac[a - b] % p;
}

inline ll calc1(int x, int t)
{
    if ((x + t) % 2 == 1)
        return 0;
    return C(t, (x + t) / 2);
}

inline ll calc2(int x, int y, int t)
{
    int X = x + y, Y = x - y;
    return calc1(X, t) * calc1(Y, t) % p;
}

int main()
{
    scanf("%d%d%d%d", &n, &x, &y, &z);
    fac[0] = 1, inv_fac[0] = 1, fac[1] = 1, inv_fac[1] = 1, inv[1] = 1;
    for (int i = 2; i <= 10000000; ++i)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
        fac[i] = fac[i - 1] * i % p;
        inv_fac[i] = inv_fac[i - 1] * inv[i] % p;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = (ans + calc2(y, z, n - i) * calc1(x, i) % p * C(n, i) % p) % p;
    printf("%lld\n", ans);
    return 0;
}