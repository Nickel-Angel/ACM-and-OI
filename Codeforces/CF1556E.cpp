/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;

const int maxn = 1e5 + 10;
int n, q, log_2[maxn];
long long c[maxn], st_max[maxn][21], st_min[maxn][21], a[maxn], b[maxn];

inline long long query_max(int l, int r)
{
    int k = log_2[r - l + 1];
    return max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
}

inline long long query_min(int l, int r)
{
    int k = log_2[r - l + 1];
    return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", b + i);
    log_2[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        c[i] = c[i - 1] - a[i] + b[i];
        st_max[i][0] = c[i];
        st_min[i][0] = c[i];
        log_2[i] = log_2[i >> 1] + 1;
    }
    log_2[0] = 0;
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l, r;
    while (q--)
    {
        scanf("%d%d", &l, &r);
        if (c[l - 1] != c[r] || query_min(l, r) < c[l - 1])
            puts("-1");
        else
            printf("%lld\n", query_max(l, r) - c[l - 1]);
    }
    return 0;
}