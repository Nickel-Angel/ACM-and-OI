/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (n <= 2 * k - 1 && m <= 2 * k - 1)
        puts("Alice");
    else
        puts(n % 2 == 1 && m % 2 == 1 ? "Alice" : "Bob");
    return 0;
}