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

int n, m, k;

inline void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    k -= 2;
    if (m < n - 1 || 1ll * m > 1ll * n * (n - 1) / 2 || k < 0)
    {
        puts("NO");
        return;
    }
    if (n == 1)
    {
        puts("YES");
        return;
    }
    if (1ll * m == 1ll * n * (n - 1) / 2)
    {
        puts(k == 0 ? "NO" : "YES");
        return;
    }
    puts(k > 1 ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}