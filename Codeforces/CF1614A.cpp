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
using std::vector;

int n, l, r, k;

inline void solve()
{
    scanf("%d%d%d%d", &n, &l, &r, &k);
    vector<int> list;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        if (x >= l && x <= r)
            list.push_back(x);
    }
    int ans = 0;
    sort(list.begin(), list.end());
    for (int c : list)
    {
        if (k < c)
            break;
        k -= c;
        ++ans;
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