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

int n, a[410];

int main()
{
    scanf("%d", &n);
    int cur = 0, ans = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        cur = (cur - x + 360) % 360;
        a[i] = cur;
    }
    a[n + 1] = 360;
    sort(a, a + n + 2);
    for (int i = 0; i <= n; ++i)
        ans = max(ans, a[i + 1] - a[i]);
    printf("%d\n", ans);
    return 0;
}