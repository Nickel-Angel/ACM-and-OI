/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn], cnt[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        cnt[a[i]] = 0;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = n, j = n; i > 0; --i)
    {
        if (b[i] == b[i - 1])
        {
            ++cnt[b[i]];
            continue;
        }
        if (a[j] == b[i])
        {
            --j;
            continue;
        }
        if (cnt[a[j]])
        {
            --cnt[a[j]];
            --j, ++i;
            continue;
        }
        puts("No");
        return;
    }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}