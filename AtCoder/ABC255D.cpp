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
int n, q, a[maxn];
ll sum[maxn];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int pos;
    ll x;
    while (q--)
    {
        scanf("%lld", &x);
        pos = std::upper_bound(a + 1, a + n + 1, x) - a;
        if (pos == n + 1)
        {
            printf("%lld\n", n * x - sum[n]);
            continue;
        }
        printf("%lld\n", (pos - 1) * x - sum[pos - 1] - (n - pos + 1) * x + sum[n] - sum[pos - 1]);
    }
    return 0;
}