/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

char s[110], t[110];
int cnt[26];

inline void solve()
{
    scanf("%s%s", s, t);
    int n = strlen(s);
    for (int i = 0; i < 26; ++i)
        cnt[i] = 0;
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    if (t[0] == 'a' && t[1] == 'b' && t[2] == 'c' && cnt[0] && cnt[1] && cnt[2])
    {
        for (int i = 0; i < cnt[0]; ++i)
            putchar('a');
        int key = 0;
        for (int i = 2; i < 26; ++i)
        {
            if (cnt[i])
            {
                key = i;
                break;
            }
        }
        if (!key)
        {
            for (int i = 0; i < cnt[1]; ++i)
                putchar('b');
        }
        else
        {
            for (int i = 0; i < cnt[key]; ++i)
                putchar('a' + key);
            for (int i = 0; i < cnt[1]; ++i)
                putchar('b');
            for (int i = 2; i < 26; ++i)
            {
                if (i == key)
                    continue;
                for (int j = 0; j < cnt[i]; ++j)
                    putchar('a' + i);
            }
        }
        puts("");
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
            putchar('a' + i);
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