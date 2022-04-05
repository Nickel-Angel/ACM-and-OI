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
int n, c[maxn], a[maxn];

inline void solve()
{
    scanf("%d", &n);
    int pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", c + i);
        if (c[i] == 1)
            pos = i;
    }
    if (!pos)
    {
        puts("No");
        return;
    }
    for (int i = pos; i <= n; ++i)
        a[i - pos + 1] = c[i];
    for (int i = 1; i < pos; ++i)
        a[n - pos + i + 1] = c[i];
    int d = 0;
    if (n > 1 && a[2] != 2)
    {
        puts("No");
        return;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (d < 0 || a[i] == 1)
        {
            puts("No");
            return;
        }
        if (a[i] > a[i - 1])
        {
            if (a[i] - a[i - 1] > 1)
            {
                puts("No");
                return;
            }
            ++d;
        }
        else
            d += a[i] - a[i - 1];
    }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}