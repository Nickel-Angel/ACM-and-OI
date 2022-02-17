/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, k, match[(1 << 16) + 10];

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        match[i] = (n - 1) ^ i;
    if (k == n - 1)
    {
        if (n == 4)
        {
            puts("-1");
            return;
        }
        match[1] = 3, match[3] = 1;
        match[3 ^ (n - 1)] = 0, match[0] = 3 ^ (n - 1);
        match[n - 2] = n - 1, match[n - 1] = n - 2;
    }
    else
    {
        match[0] = match[k], match[match[k]] = 0;
        match[n - 1] = k, match[k] = n - 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i < match[i])
            printf("%d %d\n", i, match[i]);
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