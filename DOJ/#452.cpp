/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1e6 + 10;
int n, q, a[maxn], big[maxn], lock[maxn];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, opt, x, y; i <= q; ++i)
    {
        scanf("%d%d", &opt, &x);
        if (opt == 1)
        {
            scanf("%d", &y);
            lock[x] = i;
            a[x] = y;
            big[i] = 0;
        }
        else
            big[i] = x;
    }
    for (int i = q; i >= 0; --i)
        big[i] = std::max(big[i], big[i + 1]);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", std::max(a[i], big[lock[i]]), " \n"[i == n]);
    return 0;
}