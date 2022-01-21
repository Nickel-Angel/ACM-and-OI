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

const int maxn = 2e5 + 10;
char s[maxn];

inline void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    int pos = n;
    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i] - '0' + s[i + 1] - '0' >= 10)
        {
            pos = i;
            break;
        }
    }
    if (pos != n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (pos != i)
                putchar(s[i]);
            else
            {
                printf("%d", s[i] - '0' + s[i + 1] - '0');
                ++i;
            }
        }
        puts("");
        return;
    }
    putchar(s[0] + s[1] - '0');
    for (int i = 2; i < n; ++i)
        putchar(s[i]);
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