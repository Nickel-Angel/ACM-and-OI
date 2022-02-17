/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, m, a[maxn], cnt[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        cnt[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    int x = 0, y = n;
    for (int i = 1, j = 1; i <= n; ++i)
    {
        cnt[i] += cnt[i - 1];
        while (j <= i && 2 * (cnt[i] - cnt[j - 1]) >= n + m)
            ++j;
        if (j > 1 && i - j + 1 < y - x)
        {
            x = j - 1;
            y = i;
        }
    }
    printf("%d %d\n", x, y);
    int sum = 0, j = 1;
    for (int i = 1; i <= n && m > 1; ++i)
    {
        sum += x <= a[i] && a[i] <= y ? 1 : -1;
        if (sum > 0)
        {
            sum = 0;
            printf("%d %d\n", j, i);
            j = i + 1;
            --m;
        }
    }
    printf("%d %d\n", j, n);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}