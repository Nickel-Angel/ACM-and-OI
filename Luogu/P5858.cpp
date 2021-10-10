/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e3 + 10;
int n, w, s, a[maxn], q[maxn];
long long f[maxn][maxn];

int main()
{
    scanf("%d%d%d", &n, &w, &s);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            f[i][j] = -1e18;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int L = 1, R = 0;
        q[++R] = w;
        for (int j = w; j > 0; --j)
        {
            while (L <= R && q[L] > std::min(w, j + s - 1))
                ++L;
            while (L <= R && f[i - 1][q[R]] < f[i - 1][j - 1])
                --R;
            q[++R] = j - 1;
            f[i][j] = f[i - 1][q[L]] + 1ll * a[i] * j;
        }
    }
    long long ans = -1e18;
    for (int i = 0; i <= w; ++i)
        ans = std::max(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}