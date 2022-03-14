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

inline void solve()
{
    scanf("%d", &n);
    if (n > 19)
    {
        puts("NO");
        return;
    }
    puts("YES");
    int x = 1;
    for (int i = 1; i <= n; ++i)
    {
        printf("%d%c", x, " \n"[i == n]);
        x *= 3;
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