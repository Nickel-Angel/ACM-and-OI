/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
const long long inf = 1e14;
int n, a[maxn];
long long sum[maxn], f[maxn][510];

inline void solve()
{
    scanf("%d", &n);
    int k = 1;
    while ((k + 1) * k / 2 <= n)
        ++k;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n + 1; ++i)
    {
        f[i][0] = inf;
        for (int j = 1; j < k; ++j)
            f[i][j] = -inf;
    }
    int ans = 1;
    for (int i = n; i > 0; --i)
    {
        for (int j = 1; j < k; ++j)
        {
            f[i][j] = f[i + 1][j];
            if (i + j - 1 <= n && f[i + j][j - 1] > sum[i + j - 1] - sum[i - 1])
                f[i][j] = std::max(f[i][j], sum[i + j - 1] - sum[i - 1]);
            if (f[i][j] > 0)
                ans = std::max(ans, j);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}