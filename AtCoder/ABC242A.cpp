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

int a, b, c, x;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &x);
    printf("%lf\n", x <= a ? 1 : (x <= b ? 1.0 * c / (b - a) : 0));
    return 0;
}