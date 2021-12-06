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

int p1, p2;
long long x1, x2;

inline void solve()
{
    scanf("%lld%d%lld%d", &x1, &p1, &x2, &p2);
    int p_min = min(p1, p2);
    p1 -= p_min, p2 -= p_min;
    if (p1 >= 7)
    {
        puts(">");
        return;
    }
    if (p2 >= 7)
    {
        puts("<");
        return;
    }
    for (int i = 0; i < p1; ++i)
        x1 *= 10;
    for (int i = 0; i < p2; ++i)
        x2 *= 10;
    if (x1 < x2)
        puts("<");
    else if (x1 > x2)
        puts(">");
    else
        puts("=");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}