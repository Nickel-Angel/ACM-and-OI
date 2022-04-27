/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::pair;

typedef pair<int, int> P;

const int maxn = 1e5 + 10;
int n, b[maxn], c[maxn], f[maxn], cnt[2];
std::vector<P> pos;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    int p = 1, q = 1;
    pos.push_back({0, 0});
    while (p <= n && q <= n)
    {
        if (b[p] < c[q])
        {
            pos.push_back({0, b[p]});
            ++p;
        }
        else
        {
            pos.push_back({1, c[q]});
            ++q;
        }
    }
    while (p <= n)
    {
        pos.push_back({0, b[p]});
        ++p;
    }
    while (q <= n)
    {
        pos.push_back({1, c[q]});
        ++q;
    }
    f[1] = 1;
    long long len = 0, ans = 1e14;
    for (int i = 1; i <= 2 * n; ++i)
    {
        len += 1ll * f[i] * (pos[i].second - pos[i - 1].second);
        if (!pos[i].first)
            ans = std::min(ans, len + 2ll * (pos.back().second - pos[i].second));
        ++cnt[pos[i].first];
        f[i + 1] = cnt[1] < cnt[0] ? 3 : 1;
    }
    printf("%lld\n", ans);
    return 0;
}