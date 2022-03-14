/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;

int n, a[310], b[310], d[310], bucket[610], f[610][610];

inline void solve()
{
    scanf("%d", &n);
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", a + i, b + i, d + i);
        bucket[2 * i - 1] = a[i], bucket[2 * i] = b[i];
        f[i][i - 1] = 0, f[i + 1][i] = 0;
    }
    std::sort(bucket + 1, bucket + 2 * n + 1);
    int cnt = std::unique(bucket + 1, bucket + 2 * n + 1) - bucket - 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = std::lower_bound(bucket + 1, bucket + cnt + 1, a[i]) - bucket;
        b[i] = std::lower_bound(bucket + 1, bucket + cnt + 1, b[i]) - bucket;
    }
    for (int i = 1, pos; i <= cnt; ++i)
    {
        for (int l = 1, r = i; r <= cnt; ++l, ++r)
        {
            pos = 0;
            for (int k = 1; k <= n; ++k)
            {
                if (l <= a[k] && b[k] <= r && d[pos] < d[k])
                    pos = k;
            }
            if (!pos)
            {
                f[l][r] = 0;
                continue;
            }
            for (int k = a[pos]; k <= b[pos]; ++k)
                f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + d[pos]);
        }
    }
    printf("%d\n", f[1][cnt]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}