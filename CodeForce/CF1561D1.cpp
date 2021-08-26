/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 4e6 + 10;
int n, p, f[maxn];

int main()
{
    scanf("%d%d", &n, &p);
    f[1] = 1;
    long long sum = 1;
    for (int i = 2; i <= n; ++i)
    {
        f[i] = (f[i] + sum) % p;
        for (int l = 2, r; l <= i; l = r + 1)
        {
            r = i / (i / l);
            f[i] = (f[i] + 1ll * (r - l + 1) * f[i / l] % p) % p;
        }
        sum = (sum + f[i]) % p;
    }
    printf("%d\n", f[n]);
    return 0;
}