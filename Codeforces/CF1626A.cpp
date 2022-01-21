/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
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
using std::vector;
using std::pair;

typedef long long ll;

char s[60];
int cnt[30];

inline void solve()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
        ++cnt[s[i] - 'a'];
    memset(s, 0, sizeof(s));
    int p = 1;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 2)
        {
            s[p] = 'a' + i;
            s[p + 1] = 'a' + i;
            p += 2;
        }
    }
    printf("%s", s + 1);
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 1)
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