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

int n;

int main()
{
    scanf("%d", &n);
    if (n == 1)
    {
        puts("Yes");
        return 0;
    }
    puts(n > 4 ? "Yes" : "No");
    return 0;
}