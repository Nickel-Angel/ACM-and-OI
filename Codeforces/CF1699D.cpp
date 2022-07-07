/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[5010], f[5010], cnt[5010];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    a[0] = 0, a[n + 1] = 0;
    int mx;
    for (int i = 1; i <= n + 1; ++i)
    {
        f[i] = -0x3f3f3f3f;
        for (int j = 1; j < i; ++j)
            cnt[a[j]] = 0;
        mx = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            if (j + 1 < i)
            {
                ++cnt[a[j + 1]];
                mx = std::max(mx, cnt[a[j + 1]]);
            }
            if (mx * 2 <= i - j - 1 && ((i ^ j) & 1) && (a[i] == a[j] || !a[i] || !a[j]))
                f[i] = std::max(f[i], f[j] + 1);
        }
    }
    printf("%d\n", f[n + 1] - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}