/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, x[maxn], y[maxn], id[maxn];

inline bool check(int d)
{
    static int q[maxn];
    int L = 1, R = 0, lower = 1e9, upper = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (L <= R && x[id[i]] - x[q[L]] >= d)
        {
            lower = std::min(lower, y[q[L]]);
            upper = std::max(upper, y[q[L]]);
            ++L;
        }
        if (upper - y[id[i]] >= d || y[id[i]] - lower >= d)
            return true;
        q[++R] = id[i];
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", x + i, y + i);
        id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](int a, int b){return x[a] < x[b];});
    int l = 0, r = 1e9, mid;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}