/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, a[maxn], f[maxn], g[32];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 31; ++j)
        {
            if ((a[i] >> j) & 1)
                f[i] = std::max(f[i], g[j] + 1);
        }
        ans = std::max(ans, f[i]);
        for (int j = 0; j < 31; ++j)
        {
            if ((a[i] >> j) & 1)
                g[j] = std::max(g[j], f[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}