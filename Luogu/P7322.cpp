#include <cstdio>
#include <cstring>

const int p = 998244353;
const int maxn = 5e5 + 10;
int n, k, fac[maxn], inv_fac[maxn];

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

inline int C(int n, int m)
{
    if (n < m)
        return 0;
    return 1ll * fac[n] * inv_fac[n - m] % p * inv_fac[m] % p;
}

int main()
{
    scanf("%d%d", &n, &k);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[n] = power(fac[n], p - 2);
    for (int i = n; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int ans = fac[n];
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + 1ll * C(n - i, k) * fac[n - k - 1] % p * fac[k] % p * (n - k) % p) % p;
        ans = (ans + 1ll * C(n - i, k - 1) * fac[n - k] % p * fac[k - 1] % p * (n - k) % p) % p;
        ans = (ans - 1ll * C(n - i, k - 1) * fac[n - k - 1] % p * fac[k - 1] % p * (i - 1) % p * (n - k) % p + p) % p;
    }
    printf("%d\n", ans);
    return 0;
}