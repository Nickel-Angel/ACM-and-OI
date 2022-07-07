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

int n, m, a[] = {0, 1, 1, 0}, b[] = {1, 0, 0, 1};

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        if (i % 4 > 1)
        {
            for (int j = 0; j < m; ++j)
                printf("%d%c", b[j % 4], " \n"[j == m - 1]);
        }
        else
        {
            for (int j = 0; j < m; ++j)
                printf("%d%c", a[j % 4], " \n"[j == m - 1]);
        }
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