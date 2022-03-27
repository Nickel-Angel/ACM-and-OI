/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e6 + 10;
int n, a[maxn], s[maxn], top, f[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        while (top && a[s[top]] < a[i])
        {
            f[s[top]] = i;
            --top;
        }
        s[++top] = i;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", f[i], " \n"[i == n]);
    return 0;
}