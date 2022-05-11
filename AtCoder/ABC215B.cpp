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

ll n;

int main()
{
    scanf("%lld", &n);
    for (int i = 63; i >= 0; --i)
    {
        if ((n >> i) & 1)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}