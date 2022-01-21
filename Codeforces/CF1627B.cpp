/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, m, a[maxn];

inline int dis(int a, int b, int c, int d)
{
    return abs(a - c) + abs(b - d);
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int pos = (i - 1) * m + j;
            a[pos] = dis(i, j, 1, 1);
            a[pos] = std::max(a[pos], dis(i, j, n, 1));
            a[pos] = std::max(a[pos], dis(i, j, 1, m));
            a[pos] = std::max(a[pos], dis(i, j, n, m));
        }
    }
    std::sort(a + 1, a + n * m + 1);
    for (int i = 1; i <= n * m; ++i)
        printf("%d ", a[i]);
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}