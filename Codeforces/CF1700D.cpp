/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>

const int maxn = 2e5 + 10;
int n, q;
long long v[maxn], f[maxn], ans[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", v + i);
        v[i] += v[i - 1];
        f[i] = std::max(f[i - 1], (v[i] + i - 1) / i);
    }
    for (int i = 1; i <= n; ++i)
        ans[i] = std::max(f[i], (v[n] + i - 1) / i);
    int t, l, r, mid;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &t);
        l = 1, r = n;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (ans[mid] > t)
                l = mid + 1;
            else
                r = mid;
        }
        printf("%d\n", ans[l] > t ? -1 : l);
    }
    return 0;
}