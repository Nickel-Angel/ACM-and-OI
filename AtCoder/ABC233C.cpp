/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long ll;

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;

int n;
ll x, ans;

void dfs(const vector<vector<ll>> &a, int i, ll cur)
{
    //printf("%d %lld\n", i, cur);
    if (cur > x)
        return;
    if (i == n)
    {
        if (cur == x)
            ++ans;
        return;
    }
    for (unsigned j = 0; j < a[i].size(); ++j)
    {
        if (cur * a[i][j] > x)
            continue;
        dfs(a, i + 1, cur * a[i][j]);
    }
}

int main()
{
    scanf("%d%lld", &n, &x);
    vector<vector<ll>> a(n);
    for (int i = 0, l; i < n; ++i)
    {
        vector<ll> p;
        scanf("%d", &l);
        for (int j = 0; j < l; ++j)
        {
            ll y;
            scanf("%lld", &y);
            p.push_back(y);
        }
        a[i] = p;
    }
    dfs(a, 0, 1);
    printf("%lld\n", ans);
    return 0;
}