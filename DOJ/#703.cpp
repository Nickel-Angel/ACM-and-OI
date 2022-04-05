/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 3e5 + 10;
int n, a[maxn], d[maxn], f[maxn], g[maxn][31], lb[maxn];

inline int calc(int l, int r)
{
    if (a[l] == 0)
        return 1;
    for (int i = l; i <= r + 1; ++i)
        memset(g[i], 0, sizeof(g[i]));
    for (int i = l; i <= r; ++i)
        g[i][lb[i]] = i;
    for (int j = 1; j <= 30; ++j)
    {
        for (int i = l; i <= r; ++i)
        {
            if (!g[i][j] && g[i][j - 1])
                g[i][j] = g[g[i][j - 1] + 1][j - 1];
        }
    }
    for (int i = l; i <= r; ++i)
        f[i] = 1e9;
    f[l - 1] = 0;
    for (int i = l; i <= r; ++i)
    {
        f[i] = std::min(f[i], f[i - 1] + 1);
        for (int j = 0; j <= 30; ++j)
        {
            if (g[i][j])
                f[g[i][j]] = std::min(f[g[i][j]], f[i - 1] + 1);
        }
    }
    return f[r];
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i < n; ++i)
    {
        lb[i] = 0, d[i] = a[i + 1] - a[i];
        if (d[i])
        {
            while (d[i] % 2 == 0)
            {
                ++lb[i];
                d[i] /= 2;
            }
        }
    }
    --n;
    int ans = 1, last = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] != d[last])
        {
            ans += calc(last, i - 1);
            last = i;
        }
    }
    ans += calc(last, n);
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