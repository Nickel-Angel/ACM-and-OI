#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 4e5 + 10;
const int p = 1e9 + 7;
int n, a[maxn], fac[maxn], inv_fac[maxn];

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
    return 1ll * fac[a] * inv_fac[b] % p * inv_fac[a - b] % p;
}

int main()
{
    scanf("%d", &n);
    fac[0] = 1;
    int A = 0;
    for (int i = 0; i <= n; ++i)
    {
        scanf("%d", a + i);
        A = std::max(A, a[i]);
    }
    int bound = n + A + 1;
    for (int i = 1; i <= bound; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[bound] = power(fac[bound], p - 2);
    for (int i = bound; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (a[i] == 0)
            break;
        ans = (ans + C(i + a[i], a[i] - 1)) % p;
        //printf("%d %d %d\n", i + a[i], a[i], C(i + a[i], a[i]));
    }
    printf("%d\n", ans);
    return 0;
}