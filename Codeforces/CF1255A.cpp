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

int a, b;

inline void solve()
{
    scanf("%d%d", &a, &b);
    int ans = abs(a - b) / 5;
    switch (abs(a - b) % 5)
    {
        case 0:
            break;
        case 1:
            ans += 1;
            break;
        case 2:
            ans += 1;
            break;
        case 3:
            ans += 2;
            break;
        case 4:
            ans += 2;
            break;
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