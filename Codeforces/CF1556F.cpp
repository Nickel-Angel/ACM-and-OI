/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
int n, a[20], win[20][20], f[(1 << 18) - 5], c[20][2], cnt[2];

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            win[i][j] = 1ll * a[i] * power(a[i] + a[j], p - 2) % p;
        }
    }
    for (int S = 1; S <= (1 << n); ++S)
    {
        f[S] = 1;
        for (int T = S & (S - 1); T; T = S & (T - 1))
        {
            cnt[0] = cnt[1] = 0;
            for (int i = 0; i < n; ++i)
            {
                if ((T >> i) & 1)
                    c[++cnt[0]][0] = i;
                if (((S ^ T) >> i) & 1)
                    c[++cnt[1]][1] = i;
            }
            int res = 1;
            for (int i = 1; i <= cnt[0]; ++i)
                for (int j = 1; j <= cnt[1]; ++j)
                    res = 1ll * res * win[c[i][0]][c[j][1]] % p;
            res = 1ll * res * f[T] % p;
            f[S] = (f[S] - res + p) % p;
        }
    }
    int ans = 0;
    for (int S = 1; S <= (1 << n); ++S)
    {
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((S >> i) & 1)
                c[++cnt[0]][0] = i;
            else
                c[++cnt[1]][1] = i;
        }
        int res = 1;
        for (int i = 1; i <= cnt[0]; ++i)
            for (int j = 1; j <= cnt[1]; ++j)
                res = 1ll * res * win[c[i][0]][c[j][1]] % p;
        ans = (ans + 1ll * f[S] * res % p * cnt[0] % p) % p;
    }
    printf("%d\n", ans);
    return 0;
}