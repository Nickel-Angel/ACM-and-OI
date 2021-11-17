/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

int n;

inline long long query(int l, int r)
{
    if (l == r)
        return 0;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    static long long res;
    scanf("%lld", &res);
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    int log_n = 0;
    while ((1ll << log_n) < n)
        ++log_n;
    long long target = query(1, n);
    int k = 0;
    for (int i = log_n; i >= 0; --i)
    {
        k += (1 << i);
        long long res = query(1, min(k, n));
        if (res == target)
            k -= (1 << i);
    }
    ++k;
    int j = k - query(1, k) + query(1, k - 1);
    int i = j - 1 - query(1, j - 1) + query(1, j - 2);
    printf("! %d %d %d\n", i, j, k);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}