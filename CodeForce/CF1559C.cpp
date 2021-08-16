/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

const int maxn = 1e4 + 10;
int link[maxn];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", link + i);
        if (link[n] == 0)
        {
            for (int i = 1; i <= n + 1; ++i)
                printf("%d%c", i, " \n"[i == n + 1]);
            continue;
        }
        if (link[1] == 1)
        {
            printf("%d ", n + 1);
            for (int i = 1; i <= n; ++i)
                printf("%d%c", i, " \n"[i == n]);
            continue;
        }
        int pos = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (link[i] == 0) continue;
            if (link[i - 1] == 0)
            {
                pos = i - 1;
                break;
            }
        }
        if (!pos)
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= pos; ++i)
            printf("%d ", i);
        printf("%d ", n + 1);
        for (int i = pos + 1; i <= n; ++i)
            printf("%d%c", i, " \n"[i == n]);
    }
    return 0;
}