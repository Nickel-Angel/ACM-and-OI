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

const int maxn = 2e5 + 10;
const int p = 1e9 + 7;
int n, m;

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
    scanf("%d%d", &n, &m);
    int v = 0;
    for (int i = 1, x; i <= m; ++i)
    {
        scanf("%*d%*d%d", &x);
        v |= x;
    }
    printf("%lld\n", 1ll * v * power(2, n - 1) % p);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}