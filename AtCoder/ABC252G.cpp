/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int n, a[510], f[510][510], g[510][510];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        f[i][i] = 1, g[i][i] = 1;
    }
    a[n + 1] = n + 1;
    for (int i = 1; i < n; ++i)
    {
        for (int l = 1, r = i + 1; r <= n; ++l, ++r)
        {
            for (int j = l; j < r; ++j)
            {
                f[l][r] = (f[l][r] + 1ll * g[l][j] * f[j + 1][r] % p) % p;
                if (a[j + 1] < a[r + 1])
                    g[l][r] = (g[l][r] + 1ll * g[l][j] * f[j + 1][r] % p) % p;
            }
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}