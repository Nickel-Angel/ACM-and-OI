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

int n, a, b;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n * a; ++i)
    {
        for (int j = 0; j < n * b; ++j)
        {
            printf("%c", "#."[(i / a + j / b) % 2 == 0]);
        }
        puts("");
    }
    return 0;
}