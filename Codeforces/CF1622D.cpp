/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int p = 998244353;
int n, k, sum[5010], fac[5010], inv_fac[5010];
char s[5010];

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

inline int next(int x)
{
    int res = x + 1;
    while (res <= n && s[res] == '0')
        ++res;
    return res;
}

int main()
{
    scanf("%d%d%s", &n, &k, s + 1);
    int l = 0, r = 0;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = 1ll * fac[i - 1] * i % p;
        sum[i] = sum[i - 1] + s[i] - '0';
        if (sum[i] == k && !r)
            r = i;
    }
    inv_fac[n] = power(fac[n], p - 2);
    for (int i = n; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    if (k == 0 || r == 0)
    {
        puts("1");
        return 0;
    }
    r = next(r);
    int R = next(r);
    int ans = C(r - 1, k);
    l = next(l);
    int L = next(l);
    while (R <= n + 1)
    {
        ans = ((ans + C(R - l - 1, k)) % p + (p - C(r - l - 1, k - 1)) % p) % p;
        l = L, r = R;
        L = next(L), R = next(R);
    }
    printf("%d\n", ans);
    return 0;
}