/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const long long inf = 1e14;
const int maxn = 5e5 + 10;
int n, a[10010], d[10010];
long long f[2][maxn];

int main()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i < n; ++i)
        d[i] = a[i + 1] - a[i];
    std::sort(d + 1, d + n);
    for (int i = 1; i < n; ++i)
        sum += i * d[i];
    for (int i = 1; i <= sum; ++i)
        f[0][i] = inf;
    f[0][0] = 0;
    int cur = 0, s = 0;
    for (int i = 1; i < n; ++i)
    {
        if (d[i] == 0)
            continue;
        cur += d[i], s ^= 1;
        for (int j = 0; j <= sum; ++j)
        {
            f[s][j] = inf;
            if (j >= i * d[i])
                f[s][j] = std::min(f[s][j], f[s ^ 1][j - i * d[i]] + 2ll * j * d[i] - 1ll * i * d[i] * d[i]);
            if (j >= cur)
                f[s][j] = std::min(f[s][j], f[s ^ 1][j - cur] + 1ll * cur * cur);
        }
    }
    long long ans = inf;
    for (int i = 0; i <= sum; ++i)
    {
        if (f[s][i] < inf)
            ans = std::min(ans, n * f[s][i] - 1ll * i * i);
    }
    printf("%lld\n", ans);
    return 0;
}