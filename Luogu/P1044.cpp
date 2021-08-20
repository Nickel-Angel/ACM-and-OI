/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1010;
int n, f[maxn];

int main()
{
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            f[i] += f[j] * f[i - 1 - j];
    printf("%d\n", f[n]);
}