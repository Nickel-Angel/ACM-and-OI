/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <cstdio>
#include <cstring>

const int maxn = 2e4 + 10;
int n;
char s[maxn];

inline void solve()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n / 2; ++i)
    {
        if (s[i] == '0')
        {
            printf("%d %d %d %d\n", i + 1, n, i, n);
            return;
        }
    }
    for (int i = n / 2 + 1; i <= n; ++i)
    {
        if (s[i] == '0')
        {
            printf("%d %d %d %d\n", 1, i, 1, i - 1);
            return;
        }
    }
    printf("%d %d %d %d\n", 1, n - 1, 2, n);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}