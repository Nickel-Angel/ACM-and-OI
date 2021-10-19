/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e6 + 7;
int n, m, a[110], f[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k <= std::min(a[i], j); ++k)
            {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % p;
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}