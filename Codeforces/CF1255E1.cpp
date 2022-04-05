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

const int maxn = 1e5 + 10;
int n, a[maxn];
vector<int> pos;

inline ll calc(int d)
{
    ll res = 0;
    for (unsigned i = 0; i < pos.size(); i += d)
    {
        int mid = pos[(i + i + d - 1) / 2];
        for (unsigned j = i; j < i + d; ++j)
            res += abs(pos[j] - mid);
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i])
            pos.push_back(i);
    }
    int tot = pos.size();
    if (tot == 1)
    {
        puts("-1");
        return 0;
    }
    ll ans = 1e14;
    for (int i = 2; 1ll * i * i <= tot; ++i)
    {
        if (tot % i == 0)
        {
            ans = min(ans, calc(i));
            while (tot % i == 0)
                tot /= i;
        }
    }
    if (tot > 1)
        ans = min(ans, calc(tot));
    printf("%lld\n", ans);
    return 0;
}