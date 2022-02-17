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
const int inv2 = 499122177;
ll n;
int base[20], sum[20];

inline int calc(int x, int y)
{
    return 1ll * (x + y) * (y - x + 1) % p * inv2 % p;
}

int main()
{
    base[0] = 1;
    for (int i = 1; i < 18; ++i)
    {
        base[i] = 1ll * base[i - 1] * 10 % p;
        sum[i] = calc(1, base[i] - base[i - 1]);
    }
    scanf("%lld", &n);
    int ans = 0, digit = 0;
    ll x = n;
    while (x)
    {
        ++digit;
        x /= 10;
    }
    for (int i = 1; i < digit; ++i)
        ans = (ans + sum[i]) % p;
    ans = (ans + calc(1, (n + 1) % p - base[digit - 1])) % p;
    printf("%d\n", ans);
    return 0;
}