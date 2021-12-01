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
int n, a[maxn];
long long f[maxa], cnt[maxa];
vector<int> prime;
bool vis[maxa];

inline void Euler(int bound)
{
    vis[1] = true;
    for (int i = 2; i <= bound; ++i)
    {
        if (!vis[i])
            prime.push_back(i);
        for (int p : prime)
        {
            if (1ll * p * i > bound)
                break;
            vis[i * p] = true;
            if (i % p == 0)
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
        ++cnt[a[i]];
        bound = max(bound, a[i]);
    }
    Euler(bound);
    for (int j : prime)
    {
        for (int i = bound / j; i > 0; --i)
        {
            if (1ll * i * j > bound)
                break;
            cnt[i] += cnt[i * j];
        }
    }
    long long ans = 0;
    for (int i = bound; i > 0; --i)
    {
        f[i] = max(f[i], cnt[i] * i);
        for (int j : prime)
        {
            if (1ll * i * j > bound)
                continue;
            f[i] = max(f[i], 1ll * i * (cnt[i] - cnt[i * j]) + f[i * j]);
        }
        ans = max(ans, f[i]);
    }
    printf("%lld\n", ans);
    return 0;
}