/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int inf = 0x3f3f3f3f;
int n, k, a[310], c[(1 << 8) + 1], w[(1 << 8) + 1];
long long f[310][310][(1 << 8) + 1], g[2];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < (1 << k); ++i)
        scanf("%d%d", c + i, w + i);
    memset(f, -0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)
        f[i][i][a[i]] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int l = 1, r = l + i - 1; r <= n; ++l, ++r)
        {
            int rem = (i - 1) % (k - 1);
            if (rem == 0)
                rem = k - 1;
            for (int j = r - 1; j >= l; j -= k - 1)
            {
                for (int S = 0; S < (1 << rem); ++S)
                {
                    f[l][r][S << 1] = max(f[l][r][S << 1], f[l][j][S] + f[j + 1][r][0]);
                    f[l][r][S << 1 | 1] = max(f[l][r][S << 1 | 1], f[l][j][S] + f[j + 1][r][1]);
                }
            }
            if (rem == k - 1)
            {
                g[0] = g[1] = -inf;
                for (int S = 0; S < (1 << k); ++S)
                    g[c[S]] = max(g[c[S]], f[l][r][S] + w[S]);
                f[l][r][0] = g[0], f[l][r][1] = g[1];
            }
        }
    }
    long long ans = -inf;
    for (int S = 0; S < (1 << k); ++S)
        ans = max(ans, f[1][n][S]);
    printf("%lld\n", ans);
    return 0;
}