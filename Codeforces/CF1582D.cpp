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

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    if (n & 1)
    {
        if (a[3] * a[1] > 0)
        {
            b[1] = -a[2];
            b[2] = a[1] + a[3];
            b[3] = -a[2];
        }
        else
        {
            b[1] = a[2];
            b[2] = -a[1] + a[3];
            b[3] = -a[2];
        }
        for (int i = 4; i <= n; i += 2)
        {
            b[i + 1] = -a[i];
            b[i] = a[i + 1];
        }
        for (int i = 1; i <= n; ++i)
            printf("%d ", b[i]);
        puts("");
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
            printf("%d %d ", -a[i + 1], a[i]);
        puts("");
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