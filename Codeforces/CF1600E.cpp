/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    a[0] = -1, a[n + 1] = -1;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] < a[i])
            ++l;
        else
            break;
    }
    for (int i = n; i > 0; --i)
    {
        if (a[i + 1] < a[i])
            ++r;
        else
            break;
    }
    puts(((l & 1) | (r & 1)) ? "Alice" : "Bob");
    return 0;
}