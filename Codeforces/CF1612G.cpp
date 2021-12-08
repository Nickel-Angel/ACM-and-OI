/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxm = 5e5 + 10;
int m, fac[maxn], cnt[maxn];
long long n;

int main()
{
    scanf("%d", &m);
    int bound = 0;
    n = 0;
    for (int i = 1, x; i <= m; ++i)
    {
        scanf("%d", &x);
        n += x, ++cnt[x];
    }
    fac[0] = 1;
    for (int i = 1; i <= (int)1e6 + 5; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    int anscnt = 1, ansval = 0;
    for (int i = (int)1e6 + 5; i > 1; --i)
    {
        anscnt = 1ll * anscnt * fac[cnt[i]] % p * fac[cnt[i]] % p;
        ansval = (ansval + 1ll * (i - 1) * cnt[i] % p * ((n - cnt[i]) % p) % p) % p;
        n -= 2 * cnt[i];
        cnt[i - 2] += cnt[i];
    }
    anscnt = 1ll * anscnt * fac[cnt[1]] % p;
    printf("%d %d\n", ansval, anscnt);
    return 0;
}