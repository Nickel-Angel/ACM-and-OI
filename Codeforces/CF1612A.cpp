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

inline void solve()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if ((x + y) & 1)
    {
        puts("-1 -1");
        return;
    }
    if (x < y)
        printf("%d %d\n", x, (x + y) / 2 - x);
    else
        printf("%d %d\n", (x + y) / 2 - y, y);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}