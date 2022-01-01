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

int n, m, x, y, tx, ty;

inline void solve()
{
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &tx, &ty);
    printf("%d\n", min(tx >= x ? tx - x : 2 * (n - x) + (x - tx), ty >= y ? ty - y : 2 * (m - y) + (y - ty)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}