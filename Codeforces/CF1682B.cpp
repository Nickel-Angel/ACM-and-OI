/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    int x = 2147483647;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] != i)
            x &= a[i];
    }
    printf("%d\n", x);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}