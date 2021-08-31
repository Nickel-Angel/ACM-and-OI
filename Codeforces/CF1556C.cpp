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

int n, c[1010];

int main()
{
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    for (int i = 1; i <= n; i += 2)
    {
        long long rem = 1e9, cur = 0;
        for (int j = i + 1; j <= n; j += 2)
        {
            cur += c[j - 1];
            rem = min(rem, cur);
            cur -= c[j];
            if (rem >= max(0ll, cur))
            {
                ans += rem - max(0ll, cur) + 1;
                if (j == i + 1)
                    --ans;
            }
            rem = min(rem, cur);
        }
    }
    printf("%lld\n", ans);
    return 0;
}