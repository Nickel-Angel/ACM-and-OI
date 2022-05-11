/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
const int maxn= 1e4 + 10;
int n, m, f[25][maxn];

int main()
{
    scanf("%d%d", &n, &m);
    f[0][0] = 1;
    long long w;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            w = (1ll << i) * j;
            for (int k = m; k >= w; --k)
            {
                f[i + 1][k] = (f[i + 1][k] + f[i][k - w]) % p;
            }
        }
    }
    printf("%d\n", f[20][m]);
    return 0;
}