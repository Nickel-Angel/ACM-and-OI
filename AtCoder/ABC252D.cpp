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

inline long long C2(int n)
{
    return 1ll * n * (n - 1) / 2;
}

inline long long C3(int n)
{
    return 1ll * n * (n - 1) * (n - 2) / 6;
}

int main()
{
    scanf("%d", &n);
    int A = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
        A = std::max(A, a[i]);
    }
    long long ans = C3(n);
    for (int i = 1; i <= A; ++i)
    {
        ans -= C3(cnt[i]);
        ans -= C2(cnt[i]) * (n - cnt[i]);
    }
    printf("%lld\n", ans);
    return 0;
}