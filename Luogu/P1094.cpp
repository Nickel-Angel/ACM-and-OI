/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, w, p[30010];

int main()
{
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    std::sort(p + 1, p + n + 1);
    int ans = 0, l = 1, r = n;
    while (l <= r)
    {
        if (p[l] + p[r] <= w)
        {
            ++ans;
            ++l, --r;
        }
        else
        {
            ++ans;
            --r;
        }
    }
    printf("%d\n", ans);
    return 0;
}