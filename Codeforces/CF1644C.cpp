/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::max;
using std::min;
using std::pair;
using std::sort;
using std::swap;
using std::vector;

typedef long long ll;

int n, m, a[5010], f[5010][5010], g[5010][5010], ans[5010];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        for (int j = 0; j <= n; ++j)
        {
            g[i][j] = 0;
            f[i][j] = 0;
        }
    }
    g[1][0] = a[1], g[1][1] = a[1] + m;
    f[1][0] = a[1], f[1][1] = a[1] + m;
    for (int i = 2; i <= n; ++i)
    {
        g[i][0] = max(a[i], g[i - 1][0] + a[i]);
        g[i][1] = max(m, max(g[i - 1][0] + m, g[i - 1][1])) + a[i];
        for (int j = 2; j <= i; ++j)
            g[i][j] = max(max(0, g[i - 1][j]), max(0, g[i - 1][j - 1]) + m) + a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            f[i][j] = max(g[i][j], f[i - 1][j]);
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        f[n][i] = max(f[n][i], f[n][i - 1]);
        printf("%d%c", max(0, f[n][i]), " \n"[i == n]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}