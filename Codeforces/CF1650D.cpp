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

int n, a[2010], d[2010];

inline void shift(int x)
{
    int key = a[1];
    for (int i = 1; i < x; ++i)
        a[i] = a[i + 1];
    a[x] = key;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = n, j; i > 0; --i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (a[j] == i)
                break;
        }
        if (i == j)
        {
            d[i] = 0;
            continue;
        }
        d[i] = j;
        for (int k = 0; k < j; ++k)
            shift(i);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", d[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}