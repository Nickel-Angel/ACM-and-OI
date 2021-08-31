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

int c, d;

inline void solve()
{
    scanf("%d%d", &c, &d);
    if (c == d)
        printf("%d\n", c == 0 ? 0 : 1);
    else if ((c + d) & 1)
        puts("-1");
    else
        printf("2\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();    
    return 0;
}