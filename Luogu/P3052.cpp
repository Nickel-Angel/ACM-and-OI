/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, w, a[20], f[1 << 19], g[1 << 19];
long long sum[1 << 19];

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    memset(f, 0x3f, sizeof(f));
    f[0] = 1;
    for (int S = 0; S < (1 << n); ++S)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((S >> i) & 1)
                continue;
            if (g[S] + a[i] <= w)
            {
                if (f[S | (1 << i)] > f[S])
                {
                    f[S | (1 << i)] = f[S];
                    g[S | (1 << i)] = g[S] + a[i];
                }
                else if (f[S | (1 << i)] == f[S] && g[S | (1 << i)] > g[S] + a[i])
                    g[S | (1 << i)] = g[S] + a[i];
            }
            else
            {
                if (f[S | (1 << i)] > f[S] + 1)
                {
                    f[S | (1 << i)] = f[S] + 1;
                    g[S | (1 << i)] = a[i];
                }
                else if (f[S | (1 << i)] == f[S] + 1 && g[S | (1 << i)] > a[i])
                    g[S | (1 << i)] = a[i];
            }
        }
    }
    printf("%d\n", f[(1 << n) - 1]);
    return 0;
}