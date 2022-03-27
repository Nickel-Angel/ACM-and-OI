/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e5 + 10;
const int maxC = 1e6 + 10;
int n, q, C;
long long mul[maxC], ans[maxC];

int main()
{
    scanf("%d%d", &n, &C);
    for (int i = 1, c, h, d; i <= n; ++i)
    {
        scanf("%d%d%d", &c, &h, &d);
        mul[c] = std::max(mul[c], 1ll * h * d);
    }
    for (int i = 1; i <= C; ++i)
    {
        if (!mul[i])
            continue;
        for (int j = 1; i * j <= C; ++j)
            ans[i * j] = std::max(ans[i * j], mul[i] * j - 1); 
    }
    for (int i = 2; i <= C; ++i)
        ans[i] = std::max(ans[i], ans[i - 1]);
    scanf("%d", &q);
    int p;
    long long D, H;
    while (q--)
    {
        scanf("%lld%lld", &D, &H);
        p = std::lower_bound(ans + 1, ans + C + 1, D * H) - ans;
        printf("%d ", p > C ? -1 : p);
    }
    return 0;
}