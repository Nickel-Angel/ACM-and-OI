/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

int n, a[110], pre[110];

inline int query_upper(int x)
{
    printf("? ");
    for (int i = 1; i < x; ++i)
        printf("1 ");
    printf("2 ");
    for (int i = x + 1; i <= n; ++i)
        printf("1 ");
    puts("");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

inline int query_lower(int x)
{
    printf("? ");
    for (int i = 1; i < x; ++i)
        printf("2 ");
    printf("1 ");
    for (int i = x + 1; i <= n; ++i)
        printf("2 ");
    puts("");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int pos = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        x = query_lower(i);
        if (x && x < i)
            pre[i] = x;
        x = query_upper(i);
        if (x && x < i)
            pre[x] = i;
        if (!x)
            pos = i;
    }
    int cur = n;
    while (pos)
    {
        a[pos] = cur;
        pos = pre[pos];
        --cur;
    }
    printf("! ");
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}