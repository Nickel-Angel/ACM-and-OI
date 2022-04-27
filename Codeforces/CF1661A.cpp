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

int n, a[30], b[30];
ll f[30][2];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = 1; i < n; ++i)
    {
        f[i][0] = min(f[i - 1][0], f[i - 1][1]) + abs(a[i + 1] - a[i]) + abs(b[i + 1] - b[i]);
        f[i][1] = min(f[i - 1][0], f[i - 1][1]) + abs(a[i + 1] - b[i]) + abs(b[i + 1] - a[i]);
    }
    printf("%lld\n", min(f[n - 1][0], f[n - 1][1]));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}