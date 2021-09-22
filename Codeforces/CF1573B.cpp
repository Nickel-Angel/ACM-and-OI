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
int n, a[maxn], b[maxn], id[maxn][2], pos[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        a[i] = (a[i] + 1) / 2;
        id[a[i]][0] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        b[i] = b[i] / 2;
        id[b[i]][1] = i;
    }
    pos[n + 1] = n + 1;
    for (int i = n; i > 0; --i)
        pos[i] = min(pos[i + 1], id[i][1]);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, id[i][0] - 1 + pos[i] - 1);
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