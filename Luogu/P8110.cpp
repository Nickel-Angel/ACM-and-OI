/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
const int maxn = 1e5 + 10;
int n, k, a[maxn], b[maxn];

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
    scanf("%d%d", &n, &k);
    int suma = 0, sumb = 0, sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        a[i] = (a[i] % p + p) % p;
        suma = (suma + a[i]) % p;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        b[i] = (b[i] % p + p) % p;
        sumb = (sumb + b[i]) % p;
    }
    for (int i = 1; i <= n; ++i)
        sum = (sum + 1ll * a[i] * b[i] % p) % p;
    ans = 1ll * suma * sumb % p;
    if (k == 0)
    {
        printf("%d\n", n);
        return 0;
    }
    ans = 1ll * ans * power(sum, k - 1) % p;
    printf("%d\n", ans);
    return 0;
}