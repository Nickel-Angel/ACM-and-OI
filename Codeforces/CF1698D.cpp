/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n;

inline bool check(int l, int r)
{
    int res = 0, x;
    printf("? %d %d\n", l, r);
    fflush(stdout);
    for (int i = l; i <= r; ++i)
    {
        scanf("%d", &x);
        res += (l <= x && x <= r);
    }
    res = r - l + 1 - res;
    return (res ^ (r - l + 1)) & 1;
}

inline void solve()
{
    scanf("%d", &n);
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(l, mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("! %d\n", l);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}