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

int n, a, b;

inline void solve()
{
    scanf("%d%d%d", &n, &a, &b);
    if (a + b > n - 2 || abs(a - b) > 1)
    {
        puts("-1");
        return;
    }
    int l = 1, r = n;
    if (a < b)
    {
        for (int i = 1; i <= b; ++i)
        {
            printf("%d %d ", r, l);
            ++l, --r;
        }
        for (int i = l; i <= r; ++i)
            printf("%d ", i);
        puts("");
    }
    else if (a > b)
    {
        for (int i = 1; i <= a; ++i)
        {
            printf("%d %d ", l, r);
            ++l, --r;
        }
        for (int i = r; i >= l; --i)
            printf("%d ", i);
        puts("");
    }
    else
    {
        printf("%d ", l);
        ++l;
        for (int i = 1; i <= a; ++i)
        {
            printf("%d %d ", r, l);
            ++l, --r;
        }
        for (int i = l; i <= r; ++i)
            printf("%d ", i);
        puts("");
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