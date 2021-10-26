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

long long a, b, c;

inline void solve()
{
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", (a + 2 * b + 3 * c) % 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}