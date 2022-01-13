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

int n, k;

inline void solve()
{
    scanf("%d%d", &n, &k);
    if ((n + 1) / 2 < k)
    {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j && (i - 1) % 2 == 0 && k)
            {
                --k;
                putchar('R');
            }
            else
                putchar('.');
        }
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