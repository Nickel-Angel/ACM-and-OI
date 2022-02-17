/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, m, p[maxn];
long long cnt[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", p + i);
        if (i > 1)
        {
            ++cnt[std::min(p[i - 1], p[i])];
            --cnt[std::max(p[i - 1], p[i])];
        }
    }
    long long ans = 0;
    for (int i = 1, a, b, c; i < n; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        cnt[i] += cnt[i - 1];
        ans += std::min(a * cnt[i], b * cnt[i] + c);
    }
    printf("%lld\n", ans);
    return 0;
}