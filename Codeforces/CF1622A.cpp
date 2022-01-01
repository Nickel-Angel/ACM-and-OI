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
using std::vector;
using std::pair;

typedef long long ll;

inline void solve()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b == c || b + c == a || a + c == b)
    {
        puts("Yes");
        return;
    }
    if (a == b && c % 2 == 0)
    {
        puts("Yes");
        return;
    }
    if (b == c && a % 2 == 0)
    {
        puts("Yes");
        return;
    }
    if (a == c && b % 2 == 0)
    {
        puts("Yes");
        return;
    }
    puts("No");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}