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

const int maxn = 3e5 + 10;
int n, a[maxn];
long long f[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
    }
    if (n == 2)
    {
        printf("%d\n", std::min(a[1], a[2]));
        return 0;
    }
    for (int i = 1; i <= n + 2; ++i)
        f[i] = 1e16;
    f[3] = a[1];
    for (int i = 3; i <= n; ++i)
    {
        f[i + 2] = std::min(f[i + 2], f[i] + a[i]);
        f[i + 1] = std::min(f[i + 1], f[i] + a[i - 1]);   
    }
    long long ans = std::min(f[n + 1], f[n + 2]);
    for (int i = 1; i <= n + 1; ++i)
        f[i] = 1e16;
    f[2] = a[n];
    for (int i = 2; i < n; ++i)
    {
        f[i + 2] = std::min(f[i + 2], f[i] + a[i]);
        f[i + 1] = std::min(f[i + 1], f[i] + a[i - 1]);
    }
    ans = std::min({ans, f[n], f[n + 1]});
    printf("%lld\n", ans);
    return 0;
}