/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, k[110], h[110];
std::multiset<int> s;

inline ll calc(ll x, ll y)
{
    return (x + y) * (y - x + 1) / 2;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", k + i);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", h + i);
        s.insert(k[i] - h[i] + 1);
    }
    ll ans = 0, cur = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (*s.begin() <= k[i - 1])
        {
            ans += calc(cur + 1, cur + k[i] - k[i - 1]);
            cur += k[i] - k[i - 1];
        }
        else
        {
            ans += calc(1, k[i] - *s.begin() + 1);
            cur = k[i] - *s.begin() + 1;
        }
        s.erase(s.find(k[i] - h[i] + 1));
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}