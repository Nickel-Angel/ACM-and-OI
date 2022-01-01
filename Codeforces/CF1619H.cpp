/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 1e5 + 10;
int n, q, m, p[maxn], r[maxn], tar[maxn];

inline int jump(int x, int k)
{
    for (int i = 0; i < k; ++i)
        x = p[x];
    return x;
}

inline int query(int x, int k)
{
    while (k >= m)
    {
        x = tar[x];
        k -= m;
    }
    for (int i = 0; i < k; ++i)
        x = p[x];
    return x;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", p + i);
        r[p[i]] = i;
    }
    m = ceil(sqrt(n));
    for (int i = 1; i <= n; ++i)
        tar[i] = jump(i, m);
    int opt, x, y;
    while (q--)
    {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1)
        {
            std::swap(p[x], p[y]);
            std::swap(r[p[x]], r[p[y]]);
            tar[x] = jump(x, m);
            for (int i = 0; i < m; ++i)
            {
                tar[r[x]] = r[tar[x]];
                x = r[x];
            }
            tar[y] = jump(y, m);
            for (int i = 0; i < m; ++i)
            {
                tar[r[y]] = r[tar[y]];
                y = r[y];
            }
        }
        else
            printf("%d\n", query(x, y));
    }
    return 0;
}