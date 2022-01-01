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

typedef long long ll;

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::map;

const int maxn = 2e5 + 10;
map<ll, int> cnt;
int n;
ll s[maxn], k;

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", s + i);
        s[i] += s[i - 1];
    }
    ll ans = 0;
    ++cnt[0];
    for (int i = 1; i <= n; ++i)
    {
        ans += cnt[s[i] - k];
        ++cnt[s[i]];
    }
    printf("%lld", ans);
    return 0;
}