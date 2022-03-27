/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
const int maxn = 3e5 + 10;
int n, a[maxn], maxs[maxn], mins[maxn], topmax, topmin;
int f[maxn], sum[maxn];

int main()
{
    scanf("%d", &n);
    int maxres = 0, minres = 0;
    f[0] = 1, sum[0] = 1;
    for (int i = 1, j; i <= n; ++i)
    {
        scanf("%d", a + i);
        j = i - 1;
        while (topmax && a[maxs[topmax]] <= a[i])
        {
            maxres = (maxres - 1ll * (j - maxs[topmax]) * (sum[j] - sum[maxs[topmax]] % p + p) % p);
            j = maxs[topmax] - 1;
            --topmax;
        }
        maxres = (maxres + 1ll * (i - 1 - maxs[topmax]) * (sum[i - 1] - sum[maxs[topmax]]) % p + p) % p;
        maxs[++topmax] = i;
        j = i - 1;
        while (topmin && a[mins[topmin]] >= a[i])
        {
            minres = (minres - 1ll * (j - mins[topmin]) * (sum[j] - sum[mins[topmin]]) % p + p) % p;
            j = mins[topmin] - 1;
            --topmin;
        }
        minres = (minres + 1ll * (i - 1 - mins[topmin]) * (sum[i - 1] - sum[mins[topmin]]) % p + p) % p;
        mins[++topmin] = i;
        f[i] = (maxres - minres + p) % p;
        sum[i] = (sum[i - 1] + f[i]) % p;
        maxres = (maxres + 1ll * f[i] * a[maxs[topmax]] % p) % p;
        minres = (minres + 1ll * f[i] * a[mins[topmin]] % p) % p;
    }
    printf("%d\n", f[n]);
    return 0;
}