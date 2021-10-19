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

int n, a[50], b[50];

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        b[i] = abs(a[i + 1] - a[i]);
    b[n] = abs(a[n] - a[1]);
    sort(b + 1, b + n + 1);
    int pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != 0)
        {
            pos = i;
            break;
        }
    }
    if (!pos)
    {
        puts("-1");
        return;
    }
    int d = b[n];
    for (int i = pos; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            d = min(d, gcd(b[i], b[j]));
            //printf("%d %d %d\n", i, j, gcd(b[i], b[j]));
        }
    }
    printf("%d\n", d);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}