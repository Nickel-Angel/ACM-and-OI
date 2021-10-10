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

const int p = 1e9 + 7;
const int inv2 = 500000004;
const int maxn = 2e5 + 10;
int n, fac[maxn];

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

inline void solve()
{
    scanf("%d", &n);
    printf("%lld\n", 1ll * fac[2 * n] * inv2 % p);
}

int main()
{
    int t;
    fac[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}