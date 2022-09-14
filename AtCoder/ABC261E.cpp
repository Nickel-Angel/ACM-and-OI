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

const int maxn = 2e5 + 10;
int n, C, a[maxn], t[maxn], pre[2][30][maxn];

inline void calc(int k, int x)
{
    int res = x;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i] == 1)
            res &= (a[i] >> k) & 1;
        if (t[i] == 2)
            res |= (a[i] >> k) & 1;
        if (t[i] == 3)
            res ^= (a[i] >> k) & 1;
        pre[x][k][i] = res;
    }
}

int main()
{
    scanf("%d%d", &n, &C);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", t + i, a + i);
    for (int i = 0; i < 30; ++i)
        calc(i, 0), calc(i, 1);
    for (int i = 1, x; i <= n; ++i)
    {
        x = 0;
        for (int j = 0; j < 30; ++j)
            x |= (pre[(C >> j) & 1][j][i] << j);
        C = x;
        printf("%d\n", C);
    }
    return 0;
}