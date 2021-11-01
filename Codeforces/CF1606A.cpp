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

char s[110];

inline void solve()
{
    scanf("%s", s);
    int len = strlen(s);
    if (s[0] == s[len - 1])
        puts(s);
    else
    {
        s[len - 1] = s[0];
        puts(s);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();    
    return 0;
}