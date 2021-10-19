/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxa = 3e5 + 10;
int a, b, sum[maxa];

inline void solve()
{
    scanf("%d%d", &a, &b);
    //printf("sum %d %d\n", sum[a - 1], sum[a - 1] ^ b);
    if ((sum[a - 1] ^ b) == a)
        printf("%d\n", a + 2);
    else if (sum[a - 1] == b)
        printf("%d\n", a);
    else
        printf("%d\n", a + 1);
    //printf("%d\n", sum[a - 1] ^ b == a ? a + 2 : (sum[a - 1] == b ? a : a + 1)); 
}

int main()
{
    int t;
    sum[0] = 0;
    for (int i = 1; i <= 300000; ++i)
        sum[i] = sum[i - 1] ^ i;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}