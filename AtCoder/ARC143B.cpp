/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int p = 998244353;
int n, fac[250010], inv_fac[250010];

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

inline int C(int a, int b)
{
    if (a < b)
        return 0;
    return 1ll * fac[a] * inv_fac[b] % p * inv_fac[a - b] % p;
}

int main()
{
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n * n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[n * n] = power(fac[n * n], p - 2);
    for (int i = n * n; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int ans = 0;
    for (int i = n; i <= n * n - n + 1; ++i)
        ans = (ans + 1ll * C(i - 1, n - 1) * C(n * n - i, n - 1) % p) % p;
    ans = 1ll * n * n * fac[(n - 1) * (n - 1)] % p * fac[n - 1] % p * fac[n - 1] % p * ans % p;
    ans = (fac[n * n] - ans + p) % p;
    printf("%d\n", ans);
    return 0;
}