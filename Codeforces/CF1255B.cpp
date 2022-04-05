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

int n, m;

inline void solve()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        ans += 2 * x;
    }
    if (n != m || n == 2)
    {
        puts("-1");
        return;
    }
    printf("%d\n", ans);
    for (int i = 1; i < n; ++i)
        printf("%d %d\n", i, i + 1);
    printf("%d %d\n", n, 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}