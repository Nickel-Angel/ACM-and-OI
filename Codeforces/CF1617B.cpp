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

int n;

inline void solve()
{
    scanf("%d", &n);
    if (n & 1)
    {
        if ((n - 1) / 2 % 2)
        {
            printf("%d %d %d\n", (n - 1) / 2 - 2, (n - 1) / 2 + 2, 1);
        }
        else
        {
            printf("%d %d %d\n", (n - 1) / 2 - 1, (n - 1) / 2 + 1, 1);
        }
    }
    else
    {
        printf("%d %d %d\n", n / 2 - 1, n / 2, 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}