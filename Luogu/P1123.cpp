/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, t[1010], id[1010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", t + i);
        id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return t[x] < t[y];});
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        printf("%d%c", id[i], " \n"[i == n]);
        ans += t[id[i]] * (n - i);
    }
    printf("%.2lf\n", ans / n);
    return 0;
}