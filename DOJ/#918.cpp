/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>

const int maxn = 1e6 + 10;
int n;

int main()
{
    scanf("%d", &n);
    long long neg = 0, pos = 0, pre, x;
    scanf("%lld", &pre);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%lld", &x);
        if (x > pre)
            pos += x - pre;
        else
            neg += pre - x;
        pre = x;
    }
    printf("%lld\n%lld\n", std::max(pos, neg), llabs(pos - neg) + 1);
    return 0;
}