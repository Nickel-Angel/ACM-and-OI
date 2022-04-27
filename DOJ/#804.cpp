/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, k, a[2010][2010];

inline long long calc_row(int x)
{
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res += (a[x][1] - a[i][1] + k) % k;
    for (int i = 1; i <= m; ++i)
        res += (k - a[x][i]) % k;
    return res;
}

inline long long calc_column(int y)
{
    long long res = 0;
    for (int i = 1; i <= m; ++i)
        res += (a[1][y] - a[1][i] + k) % k;
    for (int i = 1; i <= n; ++i)
        res += (k - a[i][y]) % k;
    return res;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
        {
            if ((a[i][j] + a[1][1]) % k != (a[i][1] + a[1][j]) % k)
            {
                puts("-1");
                return 0;
            }
        }
    }
    long long ans = calc_row(1);
    for (int i = 2; i <= n; ++i)
        ans = std::min(ans, calc_row(i));
    for (int i = 2; i <= m; ++i)
        ans = std::min(ans, calc_column(i));
    printf("%lld\n", ans);
    return 0;
}