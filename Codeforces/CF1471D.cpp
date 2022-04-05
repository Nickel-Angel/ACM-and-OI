/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::map;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 3e5 + 10;
int n, q, a[maxn];
map<int, int> s;

inline void solve()
{
    scanf("%d", &n);
    s.clear();
    for (int i = 1, x, y; i <= n; ++i)
    {
        scanf("%d", a + i);
        x = a[i], y = 1;
        for (int j = 2, k; 1ll * j * j <= x; ++j)
        {
            if (x % j != 0)
                continue;
            k = 0;
            while (x % j == 0)
            {
                x /= j;
                ++k;
            }
            if (k & 1)
                y *= j;
        }
        y *= x;
        ++s[y];
    }
    int tot = 0, res0 = 0, res1 = 0, ex = 0;
    for (auto [p, y] : s)
    {
        if (p == 1)
        {
            tot = y;   
            continue;
        }
        if (y & 1)
            res1 = max(res1, y);
        else
        {
            res0 = max(res0, y);
            ex += y;
        }
    }
    ll w;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld", &w);
        if (w)
            printf("%d\n", max(tot + ex, res1));
        else
            printf("%d\n", max({tot, res0, res1}));
            
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