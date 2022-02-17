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

int n;
char s[110];

inline void solve()
{
    scanf("%d%s", &n, s);
    if (n >= 3)
    {
        puts("NO");
        return;
    }
    if (s[0] == s[1])
    {
        puts("NO");
        return;
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