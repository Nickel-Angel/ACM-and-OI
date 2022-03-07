/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using std::map;

map<long long, int> cnt;

const int maxn = 2e5 + 10;
int n, x, a[maxn];

inline void solve()
{
    cnt.clear();
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    int ans = 0, tar, b;
    for (auto &[A, c] : cnt)
    {
        if (!c)
            continue;
        if (cnt.count(A * x))
            tar = cnt[A * x];
        else
        {
            ans += c;
            continue;
        }
        b = std::min(c, tar);
        c -= b, tar -= b;
        cnt[A * x] = tar;
        ans += c;
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