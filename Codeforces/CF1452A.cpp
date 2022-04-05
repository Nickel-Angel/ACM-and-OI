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

int x, y;

inline void solve()
{
    scanf("%d%d", &x, &y);
    int a = min(x, y), b = max(x, y);
    printf("%d\n", 2 * a + max(0, 2 * (b - a) - 1));   
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}