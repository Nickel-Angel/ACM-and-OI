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

int n, m, cnt[40];

inline void solve()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        for (int j = 0; j < m; ++j)
            cnt[j] += (x >> j) & 1;
    }
    for (int i = 0; i < m; ++i)
    { 
        if (cnt[i] > n - cnt[i])
            ans |= (1 << i);
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