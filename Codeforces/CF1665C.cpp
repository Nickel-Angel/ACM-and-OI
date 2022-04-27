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

const int maxn = 2e5 + 10;
int n, tot, par[maxn], d[maxn];

inline bool check(int x)
{
    int rem = 0;
    for (int i = 0; i <= n; ++i)
        rem += max(0, d[i] - x);
    return rem <= x;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        d[i] = 0;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", par + i);
        ++d[par[i]];
    }
    d[0] = 1;
    sort(d, d + n + 1);
    tot = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (d[i])
        {
            d[i] = max(0, d[i] - 1 - tot);
            //printf("%d ", d[i]);
            ++tot;
        }
    }
    int l = 0, r = n, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    //printf("%lld %d ", sum, tot);
    printf("%d\n", tot + l);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}