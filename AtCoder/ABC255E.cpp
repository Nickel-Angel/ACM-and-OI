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
#include <map>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
ll s[maxn], d[maxn], x[20];
int n, m;
std::map<ll, int> cnt;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
    {
        scanf("%lld", s + i);
        if (i > 1)
            d[i - 1] = s[i] - s[i - 1];
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld", x + i);
        ++cnt[x[i]], ++cnt[s[1] - x[i]];
    }
    ll cur = d[1];
    for (int i = 3; i <= n; i += 2)
    {
        for (int j = 1; j <= m; ++j)
            ++cnt[x[j] - cur];
        cur += d[i];
    }
    cur = s[1] + d[2];
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 1; j <= m; ++j)
            ++cnt[cur - x[j]];
        cur += d[i];
    }
    int ans = 0;
    for (auto &[a, b]: cnt)
        ans = max(ans, b);
    printf("%d\n", ans);
    return 0;
}