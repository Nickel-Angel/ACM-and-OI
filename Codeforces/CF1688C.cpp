/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, cnt[26];
char s[maxn << 1];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1, len; i <= 2 * n + 1; ++i)
    {
        scanf("%s", s);
        len = strlen(s);
        for (int j = 0; j < len; ++j)
            ++cnt[s[j] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] & 1)
            putchar('a' + i);
        cnt[i] = 0;
    }
    puts("");
}   

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}