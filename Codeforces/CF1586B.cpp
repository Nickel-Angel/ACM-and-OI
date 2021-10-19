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

const int maxn = 1e5 + 10;
int n, m;
bool vis[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    for (int i = 1, x; i <= m; ++i)
    {
        scanf("%*d%d%*d", &x);
        vis[x] = true;
    }
    int key = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        key = i;
        break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i == key)
            continue;
        printf("%d %d\n", i, key);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}