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

int a, b, c;

inline void solve()
{
    scanf("%d%d%d", &a, &b, &c);
    if (((2 * b - c) % a == 0 && 2 * b > c) || ((2 * b - a) % c == 0 && 2 * b > a))
    {
        puts("YES");
        return;
    }
    if ((a + c) % (2 * b) == 0)
    {
        puts("YES");
        return;
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}