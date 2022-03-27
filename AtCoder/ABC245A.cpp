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

int a, b, c, d;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a < c)
    {
        puts("Takahashi");
        return 0;
    }
    if (a > c)
    {
        puts("Aoki");
        return 0;
    }
    puts(d < b ? "Aoki" : "Takahashi");
    return 0;
}