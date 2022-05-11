/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[5010], f[5010][5010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
            f[i][j] = 2;
    }
    int ans = 2;
    for (int i = 1, l, r; i <= n; ++i)
    {
        l = i - 1, r = i + 1;
        while (l > 0 && r <= n)
        {
            if (1ll * a[l] + a[r] == 2ll * a[i])
            {
                f[i][r] = std::max(f[i][r], f[l][i] + 1);
                ans = std::max(ans, f[i][r]);
                ++r;
            }
            else if (1ll * a[l] + a[r] > 2ll * a[i])
                --l;
            else
                ++r;
        }
    }
    printf("%d\n", ans);
    return 0;
}