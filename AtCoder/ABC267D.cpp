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

int n, m, a[2010];
ll f[2010][2010], best[2010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        best[i] = -1e18;
    }
    ll ans = -1e18;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = min(i, m); j > 0; --j)
        {
            f[i][j] = best[j - 1] + a[i] * j;
            best[j] = max(best[j], f[i][j]);
            if (j == m)
                ans = max(ans, f[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}