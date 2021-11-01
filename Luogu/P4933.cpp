/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
const int offset = 20005;
int n, h[1010], f[1010][40010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", h + i);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + i) % p;
        for (int j = 1; j < i; ++j)
        {
            int d = h[i] - h[j] + offset;
            ans = (ans + f[j][d]) % p;
            f[i][d] = (f[i][d] + f[j][d] + 1) % p;
        }
    }
    printf("%d\n", ans);
    return 0;
}