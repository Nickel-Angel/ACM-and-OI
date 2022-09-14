/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 3e6 + 10;
const int p = 998244353;
int n, R, G, B, k, L, fac[maxn], inv_fac[maxn];

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
    return a >= b ? 1ll * fac[a] * inv_fac[b] % p * inv_fac[a - b] % p : 0;
}

int main()
{
    scanf("%d%d%d%d", &R, &G, &B, &k);
    n = R + G + B, L = min(R, G);
    fac[0] = 1;
    for (int i = 1; i <= 3000000; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[3000000] = power(fac[3000000], p - 2);
    for (int i = 3000000; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int ans = 0, cur;
    for (int i = k; i <= L; ++i)
    {
        cur = 1ll * C(i, k) * C(n - i, i) % p;
        cur = 1ll * cur * fac[n - 2 * i] % p * inv_fac[R - i] % p * inv_fac[G - i] % p * inv_fac[B] % p;
        if ((i ^ k) & 1)
            ans = (ans - cur + p) % p;
        else
            ans = (ans + cur) % p;
    }
    printf("%d\n", ans);
    return 0;
}