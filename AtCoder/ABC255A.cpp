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

int n, m, a[3][3];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < 3; ++i)
        for (int j = 1; j < 3; ++j)
            scanf("%d", a[i] + j);
    printf("%d\n", a[n][m]);
    return 0;
}