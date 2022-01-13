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

const int maxn = 150010;
int n, a[maxn], pre[maxn];

inline void solve()
{
    scanf("%d", &n);
    int ans = -1;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (pre[a[i]])
            ans = max(ans, pre[a[i]] + n - i);
        pre[a[i]] = i;
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