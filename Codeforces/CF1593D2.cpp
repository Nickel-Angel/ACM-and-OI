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

const int maxn = 2e6 + 10;
int n, a[50], b[50], vis[maxn], cnt[maxn], timer;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        a[i] += 1000000;
    }
    int g, cur;
    for (g = 2000001; g > 0; --g)
    {
        ++timer, cur = 0;
        for (int i = 1, x; i <= n; ++i)
        {
            x = a[i] % g;
            if (vis[x] < timer)
            {
                vis[x] = timer;
                cnt[x] = 0;
            }
            if (cur < ++cnt[x])
                cur = cnt[x];
        }
        if (cur >= n / 2)
            break;
    }
    if (g == 2000001)
        puts("-1");
    else
        printf("%d\n", g);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}