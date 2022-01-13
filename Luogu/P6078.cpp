/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int p = 2004;
int n, a, b, m[15];
ll fac;

inline ll calc(int rem)
{
    ll P = p * fac, res = 1;
    for (int i = n + rem; i > rem; --i)
        res = res * i % P;
    return (res / fac) % p;
}

ll dfs(int cur, int val, int k, int lim)
{
    if (k > lim)
        return 0;
    if (cur == n + 1)
        return (1ll * val * calc(lim - k) % p + p) % p;
    ll res = 0;
    res = (res + dfs(cur + 1, val, k, lim)) % p;
    res = (res + dfs(cur + 1, -val, k + m[cur] + 1, lim)) % p;
    return res;
}

int main()
{
    fac = 1;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", m + i);
        fac *= i;
    }
    printf("%lld\n", (dfs(1, 1, 0, b) - dfs(1, 1, 0, a - 1) + p) % p);
    return 0;
}