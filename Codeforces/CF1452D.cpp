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
const int maxn = 2e5 + 10;
int n, f[maxn], sum[maxn];

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

int main()
{
    scanf("%d", &n);
    f[1] = 1, f[2] = 1, sum[1] = 1, sum[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        f[i] = sum[i - 1];
        sum[i] = (sum[i - 2] + f[i]) % p;
    }
    int ans = 1ll * f[n] * power(power(2, n), p - 2) % p;
    printf("%d\n", ans);
    return 0;
}