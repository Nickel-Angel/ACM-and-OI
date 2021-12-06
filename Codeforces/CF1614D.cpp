/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::max;
using std::vector;

const int maxn = 1e5 + 10;
const int maxa = 2e7 + 10;
int n, a[maxn], prime[maxa], cnt_p;
long long f[maxa], cnt[maxa];
bool vis[maxa];

inline void Euler(int bound)
{
    vis[1] = true;
    for (int i = 2; i <= bound; ++i)
    {
        if (!vis[i])
            prime[++cnt_p] = i;
        for (int j = 1; j <= cnt_p && 1ll * i * prime[j] <= bound; ++j)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    int bound = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        bound = max(bound, a[i]);
        for (int j = 1; j * j <= a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                ++cnt[j];
                if (j * j != a[i])
                    ++cnt[a[i] / j];
            }
        }
    }
    Euler(bound);
    long long ans = 0;
    for (int i = bound; i > 0; --i)
    {
        f[i] = max(f[i], cnt[i] * i);
        for (int j = 1; j <= cnt_p && 1ll * i * prime[j] <= bound; ++j)
            f[i] = max(f[i], i * (cnt[i] - cnt[i * prime[j]]) + f[i * prime[j]]);
        if (cnt[i] == n)
            ans = max(ans, f[i]);
    }
    printf("%lld\n", ans);
    return 0;
}