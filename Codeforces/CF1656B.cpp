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

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, m, a[maxn];
std::set<int> vis;

inline void solve()
{
    vis.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        vis.insert(a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis.count(a[i] - m))
        {
            puts("Yes");
            return;
        }
    }
    puts("No");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}