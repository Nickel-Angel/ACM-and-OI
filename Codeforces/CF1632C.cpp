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

int a, b;

inline void solve()
{
    scanf("%d%d", &a, &b);
    int ans = 1e9;
    for (int i = 0; i <= b; ++i)
    {
        if (b == (b | i))
            ans = min(ans, abs(a - i) + (i != b));
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