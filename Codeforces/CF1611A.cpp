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

inline void solve()
{
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        puts("0");
        return;
    }
    int flag = 1;
    while (n / 10)
    {
        flag &= n % 10 % 2;
        n /= 10;
    }
    if (n % 10 % 2 == 0)
    {
        puts("1");
        return;
    }
    puts(flag ? "-1" : "2");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}