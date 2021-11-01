/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int maxn = 3010;
int n, a[maxn];
long long s[maxn], f[maxn], g[maxn][maxn];

int main()
{
    scanf("%d", &n);
    s[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j > 0; --j)
        {
            g[i][j] = g[i][j + 1] + s[i] - s[j] + min(3ll * (i - j) * a[j], s[i] - s[j]);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            f[i] = min(f[i], f[j] + g[i][j + 1] + (s[n] - s[i]) * (4ll * (i - j) - 2));
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}