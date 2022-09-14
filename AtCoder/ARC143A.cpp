/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>

long long A[3];

int main()
{
    scanf("%lld%lld%lld", A, A + 1, A + 2);
    std::sort(A, A + 3);
    long long c = A[2] - A[0], a = A[1] - c, b = A[0] - a;
    printf("%lld\n", c >= 0 && a >= 0 && b >= 0 ? A[2] : -1ll);
    return 0;
}