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

int a, b;

inline void solve()
{
    scanf("%d%d", &a, &b);
    if (a > b)
        swap(a, b);
    if (3ll * a <= b)
    {
        printf("%d\n", a);
        return;
    }
    int k = (3ll * a - b + 1) / 2;
    printf("%d\n", k / 2 + a - k);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}