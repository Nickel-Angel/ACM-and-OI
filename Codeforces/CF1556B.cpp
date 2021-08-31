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

inline int calc(int x)
{
    int res = 0;
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if ((a[i] & 1) == x)
        {
            res += abs(i - j);
            j += 2;
        }
    }
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i] & 1];
    }
    if (abs(cnt[0] - cnt[1]) > 1)
    {
        puts("-1");
        return;
    }
    if (n & 1)
        printf("%d\n", cnt[0] > cnt[1] ? calc(0) : calc(1));
    else
        printf("%d\n", min(calc(0), calc(1)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}