/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

const int maxn = 1e6 + 10;
ll l, r;
int prime[maxn], tot;
bool vis[maxn];

inline void Euler(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
            prime[++tot] = i;
        for (int j = 1; j <= tot; ++j)
        {
            if (1ll * i * prime[j] > n)
                break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    scanf("%lld%lld", &l, &r);
    Euler(100000);
    memset(vis, 0, sizeof(vis));
    l = std::max(2ll, l);
    for (int i = 1; i <= tot; ++i)
    {
        ll j = std::max((l + prime[i] - 1) / prime[i] * prime[i], prime[i] * 2ll);
        for (; j <= r; j += prime[i])
            vis[j - l] = true;
    }
    int ans = 0;
    for (int i = 0; i <= r - l; ++i)
        ans += vis[i] ? 0 : 1;
    printf("%d\n", ans);
    return 0;
}