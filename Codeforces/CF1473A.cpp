/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, d, a[110];

inline void solve()
{
    scanf("%d%d", &n, &d);
    int fir = 100, sec = 100;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (fir > a[i])
        {
            sec = fir;
            fir = a[i];
        }
        else if (sec > a[i])
            sec = a[i];
    }
    if (sec + fir <= d)
        puts("Yes");
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > d)
            {
                puts("No");
                return;
            }
        }
        puts("Yes");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}