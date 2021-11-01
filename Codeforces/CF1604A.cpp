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
    int ans = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        ans = max(ans, x - i);
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}