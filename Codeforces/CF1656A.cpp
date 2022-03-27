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

const int maxn = 1e5 + 10;
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    int x = 0, px = 0, y = 1e9 + 1, py = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (x < a[i])
        {
            x = a[i];
            px = i;
        }
        if (y > a[i])
        {
            y = a[i];
            py = i;
        }
    }
    printf("%d %d\n", px, py);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}