/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;

long long x, y, f[(1 << 18) + 10];
int n, a[20], b[20];

inline int calc(int S, int i)
{
    int res = 0;
    for (int j = 1; j <= n; ++j)
    {
        if ((S & (1 << (j - 1))) == 0 && j < i)
            ++res;
    }
    return res;
}

inline int bitcount(int S)
{
    int res = 0;
    while (S)
    {
        S -= S & -S;
        ++res;
    }
    return res;
}

int main()
{
    scanf("%d%lld%lld", &n, &x, &y);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    f[0] = 0;
    for (int S = 1; S < (1 << n); ++S)
        f[S] = 1e18;
    for (int S = 0, cur; S < (1 << n); ++S)
    {
        cur = bitcount(S) + 1;
        for (int i = 1; i <= n; ++i)
        {
            if (S & (1 << (i - 1)))
                continue;
            f[S | (1 << (i - 1))] = min(f[S | (1 << (i - 1))], f[S] + abs(a[i] - b[cur]) * x + calc(S, i) * y);
        }
    }
    printf("%lld\n", f[(1 << n) - 1]);
    return 0;
}