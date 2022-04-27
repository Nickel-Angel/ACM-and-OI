/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
long long n;
int tot, prime[maxn];
bool vis[maxn];

inline void Euler(int n)
{
    vis[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            prime[++tot] = i;
        for (int j = 1; j <= tot && prime[j] <= n / i; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

inline void solve()
{
    scanf("%lld", &n);
    for (int i = 1; i <= tot && prime[i] <= n / prime[i]; ++i)
    {
        if (n % (1ll * prime[i] * prime[i]) == 0)
        {
            puts("YES");
            return;
        }
    }
    long long x;
    for (int i = 1; i <= tot && prime[i] < n; ++i)
    {
        if (n % prime[i] == 0)
        {
            x = sqrt(n / prime[i]);
            if (x * x == n / prime[i])
                puts("YES");
            else
                puts("NO");
            return;
        }
    }
    puts("NO");
}

int main()
{
    Euler(1000000);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();    
    return 0;
}