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

int x, y;

inline void solve()
{
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0)
    {
        puts("0");
        return;
    }
    int d = x * x + y * y;
    for (int i = 1; i * i <= d; ++i)
    {
        if (i * i == d)
        {
            puts("1");
            return;
        }
    }
    puts("2");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}