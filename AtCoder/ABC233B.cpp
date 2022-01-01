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

const int maxn = 1e5 + 10;
char s[maxn];
int l, r;

int main()
{
    scanf("%d%d%s", &l, &r, s + 1);
    std::reverse(s + l, s + r + 1);
    printf("%s", s + 1);
    return 0;
}