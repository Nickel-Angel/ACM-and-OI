/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

typedef long long ll;

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 3e5 + 10;
int n;
std::map<ll, int> cnt;

inline void solve()
{
    cnt.clear();
    scanf("%d", &n);
    int sign = 1, d = 0, x;
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        if (sign == 1)
        {
            while (!cnt.empty() && cnt.rbegin() -> first > x - d)
                cnt.erase(cnt.rbegin() -> first);
        }
        else
        {
            while (!cnt.empty() && -cnt.begin() -> first > x - d)
                cnt.erase(cnt.begin() -> first);
        }
        sign = -sign;
        ++cnt[d * sign];
        d = x - d;
        ans += cnt[-d * sign];
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