/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn], b[maxn];
char s[maxn], t[maxn];

inline void solve()
{
    scanf("%d%s%s", &n, s + 1, t + 1);
    int cnt_s = 0, cnt_t = 0;
    if (s[1] != t[1] || s[n] != t[n])
    {
        puts("-1");
        return;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (s[i] != s[i - 1])
            a[++cnt_s] = i - 1;
        if (t[i] != t[i - 1])
            b[++cnt_t] = i - 1;
    }
    if (cnt_s != cnt_t)
    {
        puts("-1");
        return;
    }
    long long ans = 0;
    for (int i = 1; i <= cnt_s; ++i)
        ans += abs(a[i] - b[i]);
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}