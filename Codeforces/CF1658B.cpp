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

const int p = 998244353;
int n, fac[1010];

inline void solve()
{
    scanf("%d", &n);
    printf("%lld\n", (n & 1) ? 0ll : 1ll * fac[n / 2] * fac[n / 2] % p);
}

int main()
{
    int t;
    fac[0] = 1;
    for (int i = 1; i <= 1000; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}