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
int n;
ll a[maxn], s[maxn], pre[3];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", s + i);
    for (int i = 1; i < n; ++i)
    {
        pre[i % 3] = pre[i % 3] + s[i + 1] - s[i];
        a[i % 3] = std::max(a[i % 3], -pre[i % 3]);
    }
    a[3] = a[0];
    if (a[1] + a[2] + a[3] > s[1])
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 3; i <= n + 2; ++i)
        a[i] = s[i - 2] - a[i - 1] - a[i - 2];
    for (int i = 1; i <= n + 2; ++i)
        printf("%lld ", a[i]);
    return 0;
}