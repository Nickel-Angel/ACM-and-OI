/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;

const int maxn = 1e6 + 10;
int n, a[maxn];
long long f[maxn][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i - 1] < a[i])
        {
            f[i][1] = max(f[i - 1][0], f[i - 1][1] + a[i] - a[i - 1]);
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        }
        else
        {
            f[i][0] = max(f[i - 1][1], f[i - 1][0] + a[i - 1] - a[i]);
            f[i][1] = max(f[i - 1][0], f[i - 1][1]);
        }
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}