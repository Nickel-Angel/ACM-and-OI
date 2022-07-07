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

ll x, a, d, n;

int main()
{
    scanf("%lld%lld%lld%lld", &x, &a, &d, &n);
    if (x <= min(a, a + (n - 1) * d))
    {
        printf("%lld\n", min(a, a + (n - 1) * d) - x);
        return 0;
    }
    if (x >= max(a, a + (n - 1) * d))
    {
        printf("%lld\n", x - max(a, a + (n - 1) * d));
        return 0;
    }
    printf("%lld\n", min(llabs(x - (a + llabs((x - a) / d) * d)), llabs(a + llabs((x - a) / d) * d + d - x)));
    return 0;
}