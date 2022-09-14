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

int n, m, x, t, d;

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &x, &t, &d);
    int a = t - x * d;
    printf("%d\n", min(a + d * x, a + d * m));
    return 0;
}