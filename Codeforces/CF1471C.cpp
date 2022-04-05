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

const int maxn = 3e5 + 10;
int n, m, c[maxn], k[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", k + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", c + i);
    ll ans = 0;
    sort(k + 1, k + n + 1, [&](int x, int y){return x > y;});
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (j < k[i])
        {
            ans += c[j];
            ++j;
        }
        else
            ans += c[k[i]];
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