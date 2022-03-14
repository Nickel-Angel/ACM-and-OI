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

int l, r, n;

inline void solve()
{
    scanf("%d%d%d", &l, &r, &n);
    if (r / n == l / n)
        printf("%d\n", r / n + r % n);
    else
        printf("%d\n", max(r / n + r % n, r / n - 1 + n - 1));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}