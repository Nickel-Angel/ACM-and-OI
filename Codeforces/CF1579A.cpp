/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

char s[60];

inline void solve()
{
    int n, cnt = 0;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == 'B')
            ++cnt;
        else
            --cnt;
    }
    puts(cnt ? "NO" : "YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}