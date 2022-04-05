/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m;
long long sum[110];
bool f[110][110];

inline bool check(long long x)
{
    memset(f, false, sizeof(f));
    f[0][0] = true;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < i; ++k)
        {
            if (((sum[i] - sum[k]) & x) < x)
                continue;
            for (int j = 1; j <= m; ++j)
                f[i][j] |= f[k][j - 1];
        }
    }
    return f[n][m];
}

int main()
{
    scanf("%d%d", &n, &m);
    long long x;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &x);
        sum[i] = sum[i - 1] + x;
    }
    long long ans = 0;
    for (int i = 60; i >= 0; --i)
    {
        if (check(ans | (1ll << i)))
            ans |= (1ll << i);
    }
    printf("%lld\n", ans);
    return 0;
}