/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int maxn = 2e5 + 10;
int n, x[maxn], y[maxn];
ll s[maxn];

inline ll cross(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}

inline ll calc(int l, int r)
{
    return s[r] - s[l] + cross(x[r], y[r], x[l], y[l]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        x[i + n] = x[i], y[i + n] = y[i];
    }
    for (int i = 0; i <= 2 * n; ++i)
        s[i + 1] = s[i] + cross(x[i], y[i], x[i + 1], y[i + 1]);
    ll ans = 7e18;
    int r = 0;
    for (int l = 0; l < n; ++l)
    {
        while (calc(l, r + 1) * 4 <= s[n])
            ++r;
        ans = std::min(ans, llabs(s[n] - calc(l, r) * 4));
        ans = std::min(ans, llabs(s[n] - calc(l, r + 1) * 4));
    }
    printf("%lld\n", ans);
    return 0;
}