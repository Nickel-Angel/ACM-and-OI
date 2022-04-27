/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, a[40010], f[40010], bit[40010];

inline int lowbit(int x)
{
    return x & -x;
}

int dfs(int x)
{
    if (f[x] != -1)
        return f[x];
    int lb = lowbit(x);
    f[x] = min(dfs((x + lb) % 32768) + lb, 15 - bit[lb]);
    return f[x];
}

int main()
{
    scanf("%d", &n);
    memset(f, -1, sizeof(f));
    f[0] = 0;
    for (int i = 0; i <= 15; ++i)
        bit[1 << i] = i;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        printf("%d ", dfs(a[i]));
    }
    return 0;
}