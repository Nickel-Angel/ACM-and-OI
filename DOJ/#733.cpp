/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e7 + 10;
int n, k, cnt[maxn], prime[maxn], tot, minp[maxn];
bool vis[maxn];

inline long long power(long long a, int b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

inline void Euler(int n)
{
    prime[++tot] = 2;
    minp[1] = 1, minp[2] = 2;
    for (int i = 3; i <= n; i += 2)
    {
        minp[i + 1] = 2;
        if (!vis[i])
        {
            prime[++tot] = i;
            minp[i] = i;
        }
        for (int j = 1; j <= tot; ++j)
        {
            if (1ll * i * prime[j] > n)
                break;
            vis[i * prime[j]] = true;
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    Euler(10000000);
    scanf("%d%d", &n, &k);
    long long y, z, ans = 0;
    for (int i = 1, x, p, c; i <= n; ++i)
    {
        scanf("%d", &x);
        y = 1, z = 1;
        while (x > 1)
        {
            p = minp[x], c = 0;
            while (x % p == 0)
            {
                x /= p;
                ++c;
            }
            c %= k;
            y *= power(p, c);
            if (c)
                z *= power(p, k - c);
            if (z < 0 || z > 10000000)
                z = 0;
        }
        ans += cnt[z];
        ++cnt[y];
    }
    printf("%lld\n", ans);
    return 0;
}