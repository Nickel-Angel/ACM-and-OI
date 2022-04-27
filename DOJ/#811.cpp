/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <cstdio>
#include <cstring>

const int maxn = 1e7 + 10;
long long ans[maxn];
int prime[maxn], tot;
bool vis[maxn];

inline void Euler(int bound)
{
    vis[1] = true;
    for (int i = 2; i <= bound; ++i)
    {
        if (!vis[i])
            prime[++tot] = i;
        for (int j = 1; j <= tot; ++j)
        {
            if (1ll * i * prime[j] > bound)
                break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 3; i <= bound; ++i)
        ans[i] = ans[i - 1] + (vis[i] ? i : 2 * i);
}

int main()
{
    Euler(10000000);
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}