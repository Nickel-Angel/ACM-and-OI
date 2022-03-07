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

char s[10];

inline void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    bool r = false, g = false, b = false;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'r')
            r = true;
        if (s[i] == 'g')
            g = true;
        if (s[i] == 'b')
            b = true;
        if (s[i] == 'R' && !r)
        {
            puts("NO");
            return;
        }
        if (s[i] == 'G' && !g)
        {
            puts("NO");
            return;
        }
        if (s[i] == 'B' && !b)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}