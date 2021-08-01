#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1e3 + 10;
const int maxm = 2e5 + 10;

int n, m;
int f[maxn][maxn], g[maxm];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        f[u][v] = i;        
    }
    for (int k = m; k >= 1; --k)
    {
        for (int i = k + 1; i <= n; ++i)
            ++g[std::min(f[i][k], f[k][i])];
        for (int i = 1; i <= n; ++i)
        {
            if (!f[i][k]) continue;
            int cur = f[i][k];
            for (int j = 1; j <= n; ++j)
                f[i][j] = std::max(f[i][j], std::min(cur, f[k][j]));
        }
    }
    g[m + 1] = n;
    for (int i = m; i >= 1; --i)
        g[i] += g[i + 1];
    for (int i = 1; i <= m + 1; ++i)
        printf("%d%c", g[i], " \n"[i == m + 1]);
    return 0;
}