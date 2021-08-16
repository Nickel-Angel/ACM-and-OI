/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 5e4 + 10;
const int maxa = 1e6 + 10;
int n, L, last[maxa], f[maxn];

int main()
{
    int ans = 0;
    scanf("%d%d", &n, &L);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        for (int j = 1; j * j <= x; ++j)
        {
            if (x % j != 0) continue;
            if (j >= L)
                f[i] = std::max(f[i], f[last[j]] + 1);
            last[j] = i;
            if (x / j >= L && x / j != j)
                f[i] = std::max(f[i], f[last[x / j]] + 1);
            last[x / j] = i;
        }
        ans = std::max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}