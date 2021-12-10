/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 4e5 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum ^= a[i];
    }
    if (n & 1)
    {
        puts("Win");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (sum == a[i])
        {
            puts("Win");
            return 0;
        }
    }
    puts("Lose");
    return 0;
}