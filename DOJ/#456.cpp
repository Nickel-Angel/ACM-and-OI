/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, sum[maxn], pre[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        x %= n;
        sum[i] = (sum[i - 1] + x) % n;
        if (sum[i] == 0 || pre[sum[i]])
        {
            printf("%d\n", i - pre[sum[i]]);
            for (int j = pre[sum[i]] + 1; j <= i; ++j)
                printf("%d%c", j, " \n"[j == i]);
            return 0;
        }
        pre[sum[i]] = i;
    }
    puts("-1");
    return 0;
}