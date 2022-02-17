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

int n, a[510], pos[510];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i] == i)
            continue;
        k = i;
        break;
    }
    if (k)
        if (pos[k] < k)
            std::reverse(a + pos[k], a + k + 1);
        else
            std::reverse(a + k, a + pos[k] + 1);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}