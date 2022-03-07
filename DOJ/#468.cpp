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
int n, k, base[70];
ll a[110], v;

inline int popcount(ll x)
{
    int res = 0;
    while (x)
    {
        x -= x & -x;
        ++res;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &k);
    base[0] = 1;
    for (int i = 1; i <= k; ++i)
        base[i] = 2ll * base[i - 1] % p;
    int cnt = 0, ans = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%lld", a + i);
        x = popcount(a[i] & ~v);
        ans = (ans + 1ll * i * ((base[k - cnt] - base[k - x - cnt] + p) % p) % p) % p;
        cnt += x;
        v |= a[i];
    }
    printf("%d\n", ans);
    return 0;
}