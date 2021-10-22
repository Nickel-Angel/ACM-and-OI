/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e5 + 10;
int n;
char c, s[maxn];

inline void solve()
{
    scanf("%d %c", &n, &c);
    scanf("%s", s + 1);
    int flag = 1;
    for (int i = 1; i <= n; ++i)
        flag &= (s[i] == c);
    if (flag)
    {
        puts("0");
        return;
    }
    flag = 0;
    for (int i = n / 2 + 1; i <= n; ++i)
    {
        if (s[i] == c)
            flag = i;
    }
    if (flag)
        printf("1\n%d\n", flag);
    else
        printf("2\n%d %d\n", n, n - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}