/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
const int maxn = 2e6 + 10;
int m, n, cnt[1010], tot;
int fac[maxn], inv_fac[maxn];

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

inline void solve()
{
    tot = 0;
    memset(cnt, 0, sizeof(cnt));   
    scanf("%d%d", &m, &n);
    int tmp = m;
    for (int i = 2; 1ll * i * i <= tmp; ++i)
    {
        if (tmp % i != 0)
            continue;
        ++tot;
        while (tmp % i == 0)
        {
            tmp /= i;
            ++cnt[tot];
        }
    }
    if (tmp > 1)
    {
        ++tot;
        cnt[tot] = 1;
    }
    int ans = power(2, n - 1);
    for (int i = 1; i <= tot; ++i)
        ans = 1ll * ans * C(n + cnt[i] - 1, cnt[i]) % p;
    printf("%d\n", ans);
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 2000000; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[2000000] = power(fac[2000000], p - 2);
    for (int i = 2000000; i >= 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}