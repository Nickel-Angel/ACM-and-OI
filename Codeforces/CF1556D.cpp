/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, k;
long long a[10010];

inline int query_and(int i, int j)
{
    int res;
    printf("and %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

inline int query_or(int i, int j)
{
    int res;
    printf("or %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

inline void finish(int x)
{
    printf("finish %d\n", x);
    fflush(stdout);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; ++i)
        a[i] = query_and(1, i) + query_or(1, i);
    int x = query_and(2, 3) + query_or(2, 3);
    a[1] = (a[2] + a[3] - x) / 2;
    for (int i = 2; i <= n; ++i)
        a[i] -= a[1];
    std::sort(a + 1, a + n + 1);
    finish(a[k]);
    return 0;
}