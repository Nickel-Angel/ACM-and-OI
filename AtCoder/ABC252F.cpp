/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n;
long long L, a[maxn];
std::priority_queue<ll, vector<ll>, std::greater<ll>> q;

int main()
{
    scanf("%d%lld", &n, &L);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        L -= a[i];
        q.push(a[i]);
    }
    if (L > 0)
    {
        q.push(L);
        ++n;
    }
    ll x, y;
    for (int i = 1; i < n; ++i)
    {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        q.push(x + y);
        ans += x + y;
    }
    printf("%lld\n", ans);
    return 0;
}