/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
int f[2010][2010], ans[2010];

int main()
{
    f[0][0] = 1, f[1][1] = 1;
    ans[1] = 1;
    for (int i = 2; i <= 2000; ++i)
    {
        for (int h = 2; h <= 20; ++h)
        {
            for (int j = 0; j < i; ++j)
            {
                f[i][h] = (f[i][h] + 1ll * f[j][h - 1] * f[i - j - 1][h - 1] % p) % p;
                f[i][h] = (f[i][h] + 1ll * f[j][h - 2] * f[i - j - 1][h - 1] % p) % p;
                f[i][h] = (f[i][h] + 1ll * f[j][h - 1] * f[i - j - 1][h - 2] % p) % p;
            }
            ans[i] = (ans[i] + f[i][h]) % p;
        }
    }
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}