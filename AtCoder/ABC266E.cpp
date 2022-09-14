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

int n;
double f[110];

int main()
{
    scanf("%d", &n);
    f[1] = 3.5;
    for (int i = 1, x; i <= n; ++i)
    {
        x = f[i - 1];
        f[i] = (f[i - 1] * x + (7 + x) * (6 - x) / 2) / 6;
    }
    printf("%lf\n", f[n]);
    return 0;
}