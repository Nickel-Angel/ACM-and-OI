/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[1010], f[20010];

inline int calc(int x)
{
    int cur = n, res = 0;
    while (x)
    {
        while (x < a[cur])
            --cur;
        res += x / a[cur];
        x -= x / a[cur] * a[cur];
    }
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 20000; ++j)
        {
            if (j >= a[i])
                f[j] = std::min(f[j], f[j - a[i]] + 1);
        }
    }
    for (int i = 1; i <= 20000; ++i)
    {
        if (calc(i) > f[i])
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}