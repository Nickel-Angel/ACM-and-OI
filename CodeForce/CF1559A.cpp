/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

int main()
{
    int T, n, x, ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        scanf("%d", &ans);
        for (int i = 1; i < n; ++i)
        {
            scanf("%d", &x);
            ans &= x;
        }
        printf("%d\n", ans);
    }
    return 0;
}