/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int m, n, f[5010][5010];

int main()
{
    scanf("%d%d", &n, &m);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            f[i][j] = (f[i - 1][j - 1] + 1ll * f[i - 1][j] * (j - (i - 1) / m) % p) % p;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", f[n][i]);
    return 0;
}