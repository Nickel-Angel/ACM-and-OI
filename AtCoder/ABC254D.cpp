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
    int ans = 0;
    for (int i = 1, d, tmp; i <= n; ++i)
    {
        d = 1, tmp = i;
        for (int j = 2, cnt; j <= tmp / j; ++j)
        {
            if (tmp % j != 0)
                continue;
            cnt = 0;
            while (tmp % j == 0)
            {
                tmp /= j;
                ++cnt;
            }
            if (cnt & 1)
                d *= j;
        }
        if (tmp > 1)
            d *= tmp;
        //printf("%d%c", d, " \n"[i == n]);
        // d * i * j * j
        for (int j = 1; 1ll * j * j * d <= n; ++j)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}