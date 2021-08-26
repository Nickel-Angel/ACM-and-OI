/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int maxn = 4e6 + 10;
int n, p, f[maxn], d[maxn];

int main()
{
    scanf("%d%d", &n, &p);
    f[1] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        d[i] = (d[i] + d[i - 1]) % p;
        f[i] = (f[i] + sum) % p;
        f[i] = (f[i] + d[i]) % p;
        sum = (sum + f[i]) % p;
        for (int j = 2; i * j <= n; ++j)
        {
            d[i * j] = (d[i * j] + f[i]) % p;
            d[min((i + 1) * j, n + 1)] = (d[min((i + 1) * j, n + 1)] - f[i] + p) % p;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}