/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, t;

struct pile
{
    int m, v;

    bool operator < (const pile &rhs) const
    {
        return v * rhs.m > rhs.v * m;
    }
}p[110];

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &p[i].m, &p[i].v);
    std::sort(p + 1, p + n + 1);
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i].m <= t)
        {
            t -= p[i].m;
            ans += p[i].v;
        }
        else
        {
            ans += 1.0 * p[i].v / p[i].m * t;
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}