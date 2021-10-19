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

const int maxm = 4e5 + 10;
int n, m, x[maxm];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", x + i);
    sort(x + 1, x + m + 1);
    long long need = 0;
    int ans = 0;
    for (int i = m; i > 0; --i)
    {
        if (need >= x[i])
            break;
        need += n - x[i];
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