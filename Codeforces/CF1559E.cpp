/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>

const int maxn = 1e5 + 10;
const int p = 998244353;
int n, m, l[60], r[60], mu[maxn], f[maxn], sum[maxn];
bool vis[maxn];
std::vector<int> prime;

inline void Euler(int bound)
{
    prime.clear();
    mu[1] = 1, vis[1] = true;
    for (int i = 2; i <= bound; ++i)
    {
        if (!vis[i])
        {
            vis[i] = true;
            mu[i] = p - 1;
            prime.push_back(i);
        }
        for (auto c : prime)
        {
            if (c * i > bound) break;
            vis[c * i] = true;
            if (i % c == 0)
            {
                mu[c * i] = 0;
                break;
            }
            else
                mu[c * i] = (p - mu[i]) % p;
        }
    }
}

inline int calc(int d)
{
    int M = m / d;
    f[0] = 1;
    for (int i = 1; i <= M; ++i)
        f[i] = 0;
    for (int i = 1, L, R; i <= n; ++i)
    {
        L = (l[i] + d - 1) / d, R = r[i] / d;
        if (L > R) return 0;
        sum[0] = f[0];
        for (int j = 1; j <= M; ++j) 
            sum[j] = (sum[j - 1] + f[j]) % p;
        for (int j = 0; j <= M; ++j)
        {
            f[j] = 0;
            if (j >= L)
                f[j] = (f[j] + sum[j - L]) % p;
            if (j >= R + 1)
                f[j] = ((f[j] - sum[j - R - 1]) % p + p) % p;
        }
    }
    int res = 0;
    for (int i = 1; i <= M; ++i)
        res = (res + f[i]) % p;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", l + i, r + i);
    Euler(m);
    int ans = 0;
    for (int d = 1; d <= m; ++d)
        ans = (ans + 1ll * mu[d] * calc(d) % p) % p;
    printf("%d\n", ans);
    return 0;
}