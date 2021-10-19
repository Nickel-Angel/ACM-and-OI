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
    for (int j = 1; j <= n; ++j)
    {
        g[j][j] = s[n] - s[j];
        for (int i = j - 1; i > 0; --i)
        {
            g[i][j] = g[i + 1][j] + s[n] - s[i] + s[n] - s[j] + min(s[j] - s[i], 3ll * (j - i) * a[i] + s[n] - s[j]);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            f[i] = min(f[i], f[j] + (j != 0) * (s[n] - s[j]) + g[j + 1][i] + (s[n] - s[i]) * (i - j - 1));
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}