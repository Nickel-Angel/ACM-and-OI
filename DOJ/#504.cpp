/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

const int maxn = 2e5 + 10;
int n, a[maxn], f[maxn];
std::map<int, int> pre;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        f[i] = pre.count(a[i] - 1) ? f[pre[a[i] - 1]] + 1 : 1;
        pre[a[i]] = i;
    }
    int b = 1e9, len = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (len < f[i])
        {
            len = f[i];
            b = a[i];
        }
        else if (len == f[i] && b > a[i])
            b = a[i];
    }
    printf("%d\n", len);
    for (int i = len - 1; i >= 0; --i)
        printf("%d%c", b - i, " \n"[i == 0]);
}