/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxa = 1e6 + 10;
const int maxn = 2e5 + 10;
int n, m, a[maxn], prime[maxa], pre[maxn], suf[maxn], cnt = 0;
bool vis[maxa];

inline void Euler(int bound)
{
    vis[1] = true;
    for (int i = 2; i <= bound; ++i)
    {
        if (!vis[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt; ++j)
        {
            if (i * prime[j] > bound)
                break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    int bound = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        bound = std::max(bound, a[i]);
    }
    int p, one;
    for (int i = 1; i <= m; ++i)
    {
        one = 0;
        for (int j = 0; i + j * m <= n; ++j)
        {
            if (a[i + j * m] == 1)
                ++one;
            else if (!vis[a[i + j * m]])
            {
                pre[i + j * m] = one;
                one = 0;
            }
            else
                one = 0;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        one = 0;
        for (int j = (n - i) / m; j >= 0; --j)
        {
            if (a[i + j * m] == 1)
                ++one;
            else if (!vis[a[i + j * m]])
            {
                ans += 1ll * pre[i + j * m] * one + pre[i + j * m] + one;
                one = 0;
            }
            else
                one = 0;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    Euler(1000000);
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}