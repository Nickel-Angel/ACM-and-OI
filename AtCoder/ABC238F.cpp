/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int p = 998244353;
int n, m, f[2][310][310], rank[310], a[310], b[310];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        rank[a[i]] = b[i];
    }
    f[0][0][n + 1] = 1;
    for (int i = 1, cur, pre; i <= n; ++i)
    {
        cur = i & 1, pre = cur ^ 1; 
        memset(f[cur], 0, sizeof(f[cur]));
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 1; k <= n + 1; ++k)
            {
                if (j > 0 && k > rank[i])
                    f[cur][j][k] = (f[cur][j][k] + f[pre][j - 1][k]) % p;
                f[cur][j][min(rank[i], k)] = (f[cur][j][min(rank[i], k)] + f[pre][j][k]) % p;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; ++i)
        ans = (ans + f[n & 1][m][i]) % p;
    printf("%d\n", ans);
    return 0;
}