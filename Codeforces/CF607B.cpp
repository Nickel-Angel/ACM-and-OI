/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, c[510], f[510][510];

int main()
{
    scanf("%d", &n);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", c + i);
        f[i][i] = 1;
    }
    for (int l = 1, r = 2; r <= n; ++l, ++r)
        f[l][r] = c[l] == c[r] ? 1 : 2;
    for (int i = 3; i <= n; ++i)
    {
        for (int l = 1, r = i; r <= n; ++l, ++r)
        {
            for (int j = l; j < r; ++j)
                f[l][r] = std::min(f[l][r], f[l][j] + f[j + 1][r]);
            f[l][r] = std::min(f[l][r], f[l + 1][r - 1] + (c[l] != c[r]) * 2);
        }
    }
    printf("%d\n", f[1][n]);
    return 0;
}