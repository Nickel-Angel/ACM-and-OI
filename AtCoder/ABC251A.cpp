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

char s[10];
int n;

int main()
{
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < 6; ++i)
        putchar(s[i % n]);
    return 0;
}