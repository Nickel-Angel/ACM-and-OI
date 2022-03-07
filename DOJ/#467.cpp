/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int p = 1e9 + 7;
const int maxn = 2e6 + 10;
int n, m, x[3010], y[3010], fac[maxn], inv_fac[maxn];
int f[3010];

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

int dfs(int k)
{
    if (f[k] != -1)
        return f[k];
    int res = C(x[k] + y[k], y[k]);
    for (int i = 1; i <= m; ++i)
    {
        if (i == k)
            continue;
        if (x[i] <= x[k] && y[i] <= y[k])
            res = (res - 1ll * dfs(i) * C(x[k] - x[i] + y[k] - y[i], x[k] - x[i]) % p + p) % p; 
    }
    f[k] = res;
    return res;
}

int main()
{
    memset(f, -1, sizeof(f));
    scanf("%d%d", &n, &m);
    fac[0] = 1;
    for (int i = 1; i <= 2 * n; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[2 * n] = power(fac[2 * n], p - 2);
    for (int i = 2 * n; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", x + i, y + i);
        --x[i], --y[i];
    }
    x[++m] = n - 1, y[m] = n - 1;
    printf("%d\n", dfs(m));
    return 0;
}