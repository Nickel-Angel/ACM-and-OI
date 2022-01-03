/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;

int n, q, a[maxn], k[maxn], id[maxn], ans[maxn];
long long s[maxn];

inline void solve()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d", k + i);
        id[i] = i;
    }
    std::sort(id + 1, id + q + 1, [&](int x, int y){return k[x] > k[y];});
    double cur = 1.0 * s[n] / n;
    for (int i = 1, j = 1; i <= q; ++i)
    {
        while (j <= n && a[j] < cur - k[id[i]])
        {
            ++j;
            cur = 1.0 * (s[n] - s[j - 1]) / (n - j + 1);
        }
        ans[id[i]] = n - j + 1;
    }
    for (int i = 1; i <= q; ++i)
        printf("%d%c", ans[i], " \n"[i == q]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}