/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, f[250][250];

int main()
{
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", f[i] + i);
        ans = std::max(ans, f[i][i]);
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int l = 1, r = i; r <= n; ++l, ++r)
        {
            for (int j = l; j < r; ++j)
            {
                if (f[l][j] != 0 && f[l][j] == f[j + 1][r])
                    f[l][r] = std::max(f[l][r], f[l][j] + 1);
            }
            ans = std::max(ans, f[l][r]);
        }
    }
    printf("%d\n", ans);
    return 0;
}