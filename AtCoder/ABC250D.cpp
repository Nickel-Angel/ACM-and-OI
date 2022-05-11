/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e6 + 10;
ll n;
int prime[maxn], tot;
bool vis[maxn];

inline void Euler(int n)
{
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

int main()
{
    Euler(1e6);
    scanf("%lld", &n);
    ll q, ans = 0;
    for (int i = 2; i <= tot; ++i)
    {
        q = 1ll * prime[i] * prime[i] * prime[i];
        for (int j = 1; j < i; ++j)
        {
            if (q * prime[j] > n)
                break;
            ++ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}