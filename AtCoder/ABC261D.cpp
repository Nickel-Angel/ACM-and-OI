/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, m, x[5010], c[5010];
ll f[5010][5010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", x + i);
    for (int i = 1, a, b; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        c[a] = b;
    }
    f[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + x[i + 1] + c[j + 1]);
            f[i + 1][0] = max(f[i + 1][0], f[i][j] + c[0]);
        }
    }
    ll ans = f[n][0];
    for (int i = 1; i <= n; ++i)
        ans = max(ans, f[n][i]);
    printf("%lld\n", ans);
    return 0;
}