/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int n, m, f[260][260], C[260][260];

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
    scanf("%d%d", &n, &m);
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
    f[0][0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; j + k < n; ++k)
            {
                f[i + 1][j + k] = (f[i + 1][j + k] + 1ll * f[i][j] * C[n - 1 - j][k] % p * power(m - i, k * (k - 1) / 2 + k * j) % p) % p;
            }
        }
    }
    printf("%d\n", f[m][n - 1]);
    return 0;
}