/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, h, a[1010];

inline void solve()
{
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    if (a[n] >= h)
    {
        puts("1");
        return;
    }
    if (h % (a[n] + a[n - 1]) > a[n])
        printf("%d\n", h / (a[n] + a[n - 1]) * 2 + 2);
    else if (h % (a[n] + a[n - 1]))
        printf("%d\n", h / (a[n] + a[n - 1]) * 2 + 1);
    else
        printf("%d\n", h / (a[n] + a[n - 1]) * 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}