/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, x, a[maxn], b[maxn];

inline void solve()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    if (2 * x <= n)
    {
        puts("YES");
        return;
    }
    std::sort(b + 1, b + n + 1);
    for (int i = n - x + 1; i <= x; ++i)
    {
        if (b[i] != a[i])
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