/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n;

inline int query(int x)
{
    printf("+ %d\n", x);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int l = 1, r = n - 1, mid, x;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        x = query(n - mid % n);
        if (x == mid / n + 1)
            l = mid;
        else
            r = mid - 1;
        l += n - mid % n, r += n - mid % n;
    }
    printf("! %d\n", l);
    fflush(stdout);
    return 0;
}