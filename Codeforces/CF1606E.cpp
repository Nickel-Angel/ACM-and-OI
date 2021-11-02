#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int n, x, C[510][510], f[510][510];

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
    scanf("%d%d", &n, &x);
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {   
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
        }
    }
    for (int i = 1, sum; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j < i)
            {
                f[i][j] = power(j, i);
                continue;
            }
            sum = 0;
            for (int k = 0; k < i - 1; ++k)
                sum = (sum + 1ll * C[i][k] * power(i - 1, k) % p * f[i - k][j - i + 1] % p) % p;
            f[i][j] = (f[i][j] + f[i][i - 1]) % p;
            f[i][j] = (f[i][j] + sum) % p;
        }
    }
    printf("%d\n", f[n][x]);
    return 0;
}