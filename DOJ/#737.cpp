/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int l, r, k, prime[maxn], tot;
int cnt[maxn];

inline void Euler(int n)
{
    cnt[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!cnt[i])
            prime[++tot] = i;
        for (int j = 1; j <= tot && prime[j] <= n / i; ++j)
        {
            cnt[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] ^= 1;
        cnt[i] += cnt[i - 1];
    }
}

int main()
{
    scanf("%d%d%d", &l, &r, &k);
    if (k == 0)
    {
        puts("0");
        return 0;
    }
    Euler(r);
    int ans = -1;
    for (int i = l, j = l; i <= r; ++i)
    {
        while (j <= i && cnt[i] - cnt[j - 1] > k)
            ++j;
        if (cnt[i] - cnt[j - 1] >= k && cnt[i] - cnt[i - 1] == 1)
            ans = std::max(ans, i - j + 1);
    }
    printf("%d\n", ans);
    return 0;
}