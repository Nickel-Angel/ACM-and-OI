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

const double eps = 1e-5;
int n, par[3010];
ll x[3010], y[3010], r[3010];

inline ll dis(ll a, ll b, ll c, ll d)
{
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

inline bool unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return false;
    par[x] = y;
    return true;
}

int main()
{
    scanf("%d", &n);
    ll sx, sy, tx, ty;
    scanf("%lld%lld%lld%lld", &sx, &sy, &tx, &ty);
    int s = 0, t = 0;
    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
        scanf("%lld%lld%lld", x + i, y + i, r + i);
        if (dis(x[i], y[i], sx, sy) == r[i] * r[i])
            s = i; 
        if (dis(x[i], y[i], tx, ty) == r[i] * r[i])
            t = i;
    }
    if (!s || !t)
    {
        puts("No");
        return 0;
    }
    ll sum, sub, d;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            sum = r[i] + r[j], sub = max(r[i], r[j]) - min(r[i], r[j]);
            d = dis(x[i], y[i], x[j], y[j]);
            if (sub * sub <= d && d <= sum * sum)
                unite(i, j);
        }
    }   
    puts(find(s) == find(t) ? "Yes" : "No");
    return 0;
}