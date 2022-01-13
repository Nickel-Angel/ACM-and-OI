/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, m, bound, d[510], a[510], f[510][510];

int main()
{
    scanf("%d%d%d", &n, &m, &bound);
    for (int i = 1; i <= n; ++i)
        scanf("%d", d + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    d[++n] = m;
    memset(f, 0x3f, sizeof(f));
    f[1][1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (int k = 1; k < i; ++k)
            {
                f[i][j] = min(f[i][j], f[k][j - 1] + (d[i] - d[k]) * a[k]);
            }
        }
    }
    int ans = 0x7f7f7f7f;
    for (int i = n - bound; i <= n; ++i)
        ans = min(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}