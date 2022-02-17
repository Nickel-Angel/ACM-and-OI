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
    if (k == 1)
    {
        puts("YES");
        for (int i = 1; i <= n; ++i)
            printf("%d\n", i);
        return;
    }
    if (n & 1)
    {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 1, cnt = 1; cnt <= k; ++cnt, j += 2)
            printf("%d%c", j + 2 * i * k, " \n"[cnt == k]);
        for (int j = 2, cnt = 1; cnt <= k; ++cnt, j += 2)
            printf("%d%c", j + 2 * i * k, " \n"[cnt == k]);
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