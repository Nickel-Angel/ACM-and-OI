/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e5 + 10;
const int p = 998244353;
int n, f[maxn], g[maxn];

inline void solve()
{
    int ans = p - 1;
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; ++i)
    {
        f[i] = 0, g[i] = 0;
    }
    f[0] = 1;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        f[x + 1] = (f[x + 1] + f[x + 1]) % p;
        f[x + 1] = (f[x + 1] + f[x]) % p;
        if (x > 0)
        {
            g[x - 1] = (g[x - 1] + g[x - 1]) % p;
            g[x - 1] = (g[x - 1] + f[x - 1]) % p;
        }
        g[x + 1] = (g[x + 1] + g[x + 1]) % p;
    }
    for (int i = 0; i <= n + 1; ++i)
    {
        ans = (ans + f[i]) % p;
        ans = (ans + g[i]) % p;
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