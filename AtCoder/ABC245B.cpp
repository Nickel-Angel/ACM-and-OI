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
bool b[2010];

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        b[x] = true;
    }
    for (int i = 0; i <= 2001; ++i)
    {
        if (!b[i])
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}