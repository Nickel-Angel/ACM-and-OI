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

int a, b;

int main()
{
    scanf("%d%d", &a, &b);
    if (a == 1 && b == 10)
        puts("Yes");
    else
        puts(a + 1 == b ? "Yes" : "No");
    return 0;
}