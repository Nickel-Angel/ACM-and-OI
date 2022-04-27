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
int n, a[maxn], cnt[maxn];

int main()
{
    scanf("%d", &n);
    int A = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
        A = max(A, a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= A; ++i)
    {
        for (int j = 1; j <= A / i; ++j)
        {
            ans += 1ll * cnt[i] * cnt[j] * cnt[i * j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}