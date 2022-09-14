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

long double x, y, d;

int main()
{
    scanf("%Lf%Lf%Lf", &x, &y, &d);
    long double theta = (1.0 * d) / 180 * acos(-1);
    printf("%.8Lf %.8Lf\n", x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    return 0;
}