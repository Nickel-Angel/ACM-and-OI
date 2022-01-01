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
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n;
ll h[maxn], d[maxn];

inline bool check(int x)
{
    ll cur;
    d[n] = 0, d[n - 1] = 0;
    for (int i = n; i >= 3; --i)
    {
        d[i] += h[i] - x;
        if (d[i] < 0)
            return false;
        cur = min(h[i] / 3, (d[i] - d[i] % 3) / 3);
        d[i - 2] = cur * 2, d[i - 1] += cur, d[i] -= cur * 3; 
    }
    d[1] += h[1] - x, d[2] += h[2] - x;
    return d[1] >= 0 && d[2] >= 0;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", h + i);
    int l = 1, r = 1e9, mid, ans = 1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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