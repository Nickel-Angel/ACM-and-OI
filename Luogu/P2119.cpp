/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int n, m, a[15010], b[15010], c[15010], d[15010], val[40010], num[15010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", val + i);
        ++num[val[i]];
    }
    for (int i = 1, sum; i * 9 + 1 <= n; ++i)
    {
        sum = 0;
        for (int j = i * 9 + 2; j <= n; ++j)
        {
            sum += num[j - i * 7 - 1] * num[j - i * 9 - 1];
            c[j - i] += num[j] * sum;
            d[j] += num[j - i] * sum;
        }
        sum = 0;
        for (int j = n - i * 9 - 1; j > 0; --j)
        {
            sum += num[j + i * 8 + 1] * num[j + i * 9 + 1];
            a[j] += num[j + 2 * i] * sum;
            b[j + 2 * i] += num[j] * sum;
        }
    }
    for (int i = 1; i <= m; ++i)
        printf("%d %d %d %d\n", a[val[i]], b[val[i]], c[val[i]], d[val[i]]);
    return 0;
}