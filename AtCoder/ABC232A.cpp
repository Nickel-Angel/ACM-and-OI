/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

char s[5];

int main()
{
    scanf("%s", s);
    printf("%d\n", (s[0] - '0') * (s[2] - '0'));
    return 0;
}