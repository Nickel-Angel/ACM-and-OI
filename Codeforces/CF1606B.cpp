/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

long long n, k;

inline void solve()
{
    scanf("%lld%lld", &n, &k);
    int x = 0;
    while ((1ull << x) < k)
        ++x;
    long long cnt = x;
    cnt += max(0ull, (n - (1ull << x) + k - 1) / k);
    printf("%lld\n", cnt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}