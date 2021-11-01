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

int n, k, a[20], d[20], base[10];

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    d[1] = 0, d[n + 1] = 0;
    for (int i = 2; i <= n; ++i)
        d[i] = a[i] - a[i - 1];
    int tmp = ++k;
    int cnt = 0;
    while (tmp > 0 && cnt <= n)
    {
        ++cnt;
        tmp -= base[d[cnt]] - 1;
    }
    --cnt;
    if (cnt == n)
    {
        printf("%d", tmp);
        for (int i = 0; i < a[cnt]; ++i)
            printf("9");
    }
    else
    {
        for (int i = 1; i <= cnt; ++i)
            k -= base[d[i]] - 1;
        printf("%d", k);
        for (int i = 0; i < a[cnt]; ++i)
            printf("9");
    }
    puts("");
}

int main()
{
    base[0] = 1;
    for (int i = 1; i < 10; ++i)
        base[i] = base[i - 1] * 10;
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}