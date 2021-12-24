/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
const int maxk = 1e6 + 10;
int n, m, k, x[2], y[2], f[maxk][4];

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
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d%d%d", x, y, x + 1, y + 1);
    if (x[0] == x[1] && y[0] == y[1])
        f[0][0] = 1; 
    else if (x[0] == x[1])
        f[0][1] = 1;
    else if (y[0] == y[1])
        f[0][2] = 1;
    else
        f[0][3] = 1;
    for (int i = 1; i <= k; ++i)
    {
        f[i][0] = (f[i - 1][1] + f[i - 1][2]) % p;
        f[i][1] = ((1ll * (m - 2) * f[i - 1][1] % p + 1ll * (m - 1) * f[i - 1][0] % p) % p + f[i - 1][3]) % p;
        f[i][2] = ((1ll * (n - 2) * f[i - 1][2] % p + 1ll * (n - 1) * f[i - 1][0] % p) % p + f[i - 1][3]) % p;
        f[i][3] = ((1ll * (n - 1) * f[i - 1][1] % p + 1ll * (m - 1) * f[i - 1][2] % p) % p + 1ll * (n + m - 4) * f[i - 1][3] % p) % p;
    }   
    printf("%d\n", f[k][0]);
    return 0;
}