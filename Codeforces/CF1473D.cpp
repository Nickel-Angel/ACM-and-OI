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

const int maxn = 2e5 + 10;
int n, m, sum[maxn], pre_min[maxn], pre_max[maxn], suf_min[maxn], suf_max[maxn];
char s[maxn];

inline void solve()
{
    scanf("%d%d%s", &n, &m, s + 1);
    pre_min[0] = 0, pre_max[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        suf_min[i] = n, suf_max[i] = -n;
        sum[i] = sum[i - 1] + (s[i] == '+' ? 1 : -1);
        pre_min[i] = min(pre_min[i - 1], sum[i]);
        pre_max[i] = max(pre_max[i - 1], sum[i]);
    }
    suf_min[n + 1] = n, suf_max[n + 1] = -n;
    for (int i = n; i > 0; --i)
    {
        suf_min[i] = min(suf_min[i + 1], sum[i]);
        suf_max[i] = max(suf_max[i + 1], sum[i]);
    }
    int l, r, c;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        if (l == 1 && r == n)
        {
            puts("1");
            continue;
        }
        if (l == 1)
        {
            c = sum[r];
            printf("%d\n", max(0, suf_max[r + 1] - c) - min(0, suf_min[r + 1] - c) + 1);
            continue;
        }
        if (r == n)
        {
            printf("%d\n", pre_max[l - 1] - pre_min[l - 1] + 1);
            continue;
        }
        c = sum[r] - sum[l - 1];
        printf("%d\n", max(pre_max[l - 1], suf_max[r + 1] - c) - min(pre_min[l - 1], suf_min[r + 1] - c) + 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}