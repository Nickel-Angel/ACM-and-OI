/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[2010], b[2010], f[2010][2010];

inline int c(int x, int y)
{
    return a[x] == b[y] ? 0 : (a[x] > b[y] ? 1 : -1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    std::sort(a + 1, a + n + 1, [&](int x, int y){return x > y;});
    std::sort(b + 1, b + n + 1, [&](int x, int y){return x > y;});
    for (int i = 1; i <= n; ++i)
    {
        f[i][0] = f[i - 1][0] + c(n - i + 1, i);
        f[i][i] = f[i - 1][i - 1] + c(i, i);
        for (int j = 1; j < i; ++j)
            f[i][j] = std::max(f[i - 1][j - 1] + c(j, i), f[i - 1][j] + c(n - (i - j) + 1, i));
    }
    int ans = -n;
    for (int i = 0; i <= n; ++i)
        ans = std::max(ans, f[n][i]);
    printf("%d\n", ans * 200);
    return 0;
}