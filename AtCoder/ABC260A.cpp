/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>

char s[5];
int cnt[26];

int main()
{
    scanf("%s", s);
    for (int i = 0; i < 3; ++i)
        ++cnt[s[i] - 'a'];
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 1)
        {
            putchar('a' + i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}