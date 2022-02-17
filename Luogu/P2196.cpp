/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[30], f[30], pre[30];
bool e[30][30];

void print(int x)
{
    if (pre[x] == 0)
    {
        printf("%d", x);
        return;
    }
    print(pre[x]);
    printf(" %d", x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, x; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            scanf("%d", &x);
            e[i][j] = e[j][i] = x ? true : false;
        }
    }
    int ans = 0, t = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = a[i];
        for (int j = 1; j <= n; ++j)
        {
            if (!e[i][j])
                continue;
            if (f[i] < f[j] + a[i])
            {
                f[i] = f[j] + a[i];
                pre[i] = j;
            }
        }
        if (ans < f[i])
        {
            ans = f[i];
            t = i;
        }
    }
    print(t);
    printf("\n%d\n", ans);
    return 0;
}