/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
int n, m, k, f[110][110], C[110][110];
char s[110], t[110];

int main()
{
    scanf("%d%d%d%s%s", &n, &k, &m, s, t);
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += s[i] == t[i];
    f[0][cnt] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int q = 0; q <= n; ++q)
            {
                if ((m + j - q) & 1)
                    continue;
                if (m + j < q || m + q < j)
                    continue;
                f[i][j] = (f[i][j] + 1ll * f[i - 1][q] * C[q][(m - j + q) / 2] % p * C[n - q][(m + j - q) / 2] % p) % p;
            }
        }
    }
    printf("%d\n", f[k][n]);
    return 0;
}