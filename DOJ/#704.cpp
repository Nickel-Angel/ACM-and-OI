/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m;
long long f[(1 << 20) + 10][25];
bool e[25][25];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        e[u][v] = true, e[v][u] = true;
    }
    long long ans = 0;
    for (int u = 0; u < n; ++u)
        f[1 << u][u] = 1;
    for (int S = 0, u; S < (1 << n); ++S)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((S >> i) & 1)
            {
                u = i;
                break;
            }
        }
        for (int v = 0; v < n; ++v)
        {
            if (!((S >> v) & 1))
                continue;
            if (e[v][u])
                ans += f[S][v];
            for (int w = u + 1; w < n; ++w)
            {
                if (!e[v][w])
                    continue;
                if ((S >> w) & 1)
                    continue;
                f[S | (1 << w)][w] += f[S][v];
            }
        }
    }
    printf("%lld\n", (ans - m) / 2);
    return 0;
}