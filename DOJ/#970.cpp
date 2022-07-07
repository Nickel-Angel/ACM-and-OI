/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    long long change = 0, cur = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (i & 1)
        {
            sum += a[i];
            cur -= a[i];
        }
        else
        {
            cur += a[i];
            change = std::max(change, cur);
        }
    }
    printf("%lld\n", sum + change);
    return 0;
}