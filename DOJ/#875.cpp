/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, x, a[2510], q[2510][2510], L[2510], R[2510];
long long f[2510][2510];

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
            f[i][j] = -1e14;
    }
    f[0][0] = 0;
    L[0] = 1, R[0] = 1;
    for (int i = 1; i <= x; ++i)
        L[i] = 1, R[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            f[j][i] = (L[j - 1] <= R[j - 1]) ? f[j - 1][q[j - 1][L[j - 1]]] + a[i] : -1e14;
            //printf("%lld%c", f[j][i], " \n"[j == x]);
        }
        for (int j = 0; j <= x; ++j)
        {
            while (L[j] <= R[j] && f[j][q[j][R[j]]] < f[j][i])
                --R[j];
            if (L[j] <= R[j] && i - q[j][L[j]] >= m)
                ++L[j];
            q[j][++R[j]] = i;
        }
    }
    long long ans = -1;
    for (int i = n - m + 1; i <= n; ++i)
        ans = std::max(ans, f[x][i]);
    printf("%lld\n", ans);
    return 0;
}