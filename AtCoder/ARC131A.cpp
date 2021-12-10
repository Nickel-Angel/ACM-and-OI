/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <cstdio>
#include <cstring>

long long a, b;

int main()
{
    scanf("%lld%lld", &a, &b);
    if (b & 1)
    {
        printf("%lld\n", b / 2 * (long long)(1e9) + 5 * (long long)(1e8) + a);
        return 0;
    }
    printf("%lld\n", b / 2 * (long long)(1e9) + a);
    return 0;
}