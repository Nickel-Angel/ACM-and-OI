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

const int maxn = 2e5 + 10;
int n, a[maxn], id[maxn], pos[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y){return a[x] > a[y];});
    int l = -1, r = 1;
    pos[0] = 0;
    long long ans = 0, suml = 0, sumr = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (abs(l) < abs(r))
        {
            pos[id[i]] = l;
            ans += 2ll * abs(l) * a[id[i]];
            suml += a[id[i]];
            --l;
        }
        else
        {
            pos[id[i]] = r;
            ans += 2ll * abs(r) * a[id[i]];
            sumr += a[id[i]];
            ++r;
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i <= n; ++i)
        printf("%d%c", pos[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}