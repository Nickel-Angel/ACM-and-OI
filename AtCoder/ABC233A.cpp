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

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d", n >= m ? 0 : ((m - n) % 10 ? (m - n) / 10 + 1 : (m - n) / 10));
    return 0;
}