/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using std::pair;

typedef pair<int, int> P;

const int p = 998244353;
const int maxn = 5e4 + 10;
int n, c[maxn], tot[maxn], fac[maxn], inv_fac[maxn];
std::map<int, int> cnt;
std::vector<P> vec;

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

inline int C(int a, int b)
{
    if (a < b)
        return 0;
    return 1ll * fac[a] * inv_fac[b] % p * inv_fac[a - b] % p;
}

int main()
{
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", c + i);
        fac[i] = 1ll * fac[i - 1] * i % p;
        ++cnt[c[i]];
    }
    inv_fac[n] = power(fac[n], p - 2);
    for (int i = n; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    int total_color = cnt.size();
    for (auto &[color, time] : cnt)
        ++tot[time];
    for (int i = 1; i <= n; ++i)
    {
        if (tot[i])
            vec.push_back(P(i, tot[i]));
    }
    int ans;
    for (int i = 1; i <= n; ++i)
    {
        ans = 1ll * total_color * C(n, i) % p;
        for (auto &[x, y] : vec)
            ans = (ans - 1ll * y * C(n - x, i) % p + p) % p;
        ans = 1ll * ans * power(C(n, i), p - 2) % p;
        printf("%d\n", ans);
    }
    return 0;
}