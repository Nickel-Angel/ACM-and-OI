/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
const int p = 23333333;

int n, m, f[maxn], sum[maxn], g[320][maxn];

int main()
{
    scanf("%d", &n);
    m = sqrt(n);
    f[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < i; ++j)
            sum[j] = f[j];
        for (int j = i; j <= n; ++j)
            sum[j] = (f[j] + sum[j - i]) % p;
        for (int j = 0; j <= n; ++j)
        {
            if (j >= i * (i + 1))
                f[j] = (sum[j] - sum[j - i * (i + 1)] + p) % p;
            else
                f[j] = sum[j];
        }
    }
    g[0][0] = 1;
    int ans = f[n];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i * (m + 1); j <= n; ++j)
        {
            g[i][j] = (g[i - 1][j - (m + 1)] + g[i][j - i]) % p;
            ans = (ans + 1ll * f[n - j] * g[i][j] % p) % p;
        }
    }
    printf("%d\n", ans);
    return 0;
}