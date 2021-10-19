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

long long n;
int a[25];

inline void solve()
{
    int cnt = 0;
    scanf("%lld", &n);
    while (n)
    {
        a[++cnt] = n % 10;
        n /= 10;
    }
    int ans = 20;
    for (int i = 1, j; i <= cnt; ++i)
    {
        j = -1;
        if (a[i] == 5)
        {
            for (j = i + 1; j <= cnt; ++j)
            {
                if (a[j] == 2 || a[j] == 7)
                    break;
            }
        }
        else if (a[i] == 0)
        {
            for (j = i + 1; j <= cnt; ++j)
            {
                if (a[j] == 0 || a[j] == 5)
                    break;
            }
        }
        if (j == -1 || j == cnt + 1)
            continue;
        ans = min(ans, j - 2);
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