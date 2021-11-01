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
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (!flag)
            break;
        flag = false;
        for (int j = 2; j <= i + 1; ++j)
        {
            if (a[i] % j)
            {
                flag = true;
                break;
            }
        }
    }
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}