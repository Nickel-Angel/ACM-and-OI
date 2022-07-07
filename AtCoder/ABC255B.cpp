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

int n, m, a[1010], x[1010], y[1010];
bool vis[1010];

inline double dis(double a, double b, double c, double d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", a + i);
        vis[a[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i);
    double res, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        res = 1e14;
        for (int j = 1; j <= m; ++j)
            res = min(res, dis(x[a[j]], y[a[j]], x[i], y[i]));
        ans = max(ans, res);
    }   
    printf("%lf\n", ans);
    return 0;
}