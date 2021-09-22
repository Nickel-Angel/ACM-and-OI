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

int n;
char s[110];

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    int ans = 0;
    if (s[n] != '0')
        ans = s[n] ^ 48;
    for (int i = n - 1; i > 0; --i)
    {
        if (s[i] == '0')
            continue;
        ans += (s[i] ^ 48) + 1;
    }
    printf("%d\n", ans);
}


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}