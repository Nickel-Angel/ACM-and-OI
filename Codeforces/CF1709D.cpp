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
int n, m, q, st[maxn][21], log_2[maxn];

inline int query(int l, int r)
{
    int k = log_2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d%d", &n, &m);
    log_2[0] = -1;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", st[i]);
        log_2[i] = log_2[i >> 1] + 1;
    }
    log_2[0] = 0;
    for (int j = 1; (1 << j) <= m; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= m; ++i)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    scanf("%d", &q);
    int sx, sy, tx, ty, k, h;
    while (q--)
    {
        scanf("%d%d%d%d%d", &sx, &sy, &tx, &ty, &k);
        if (sx % k != tx % k || sy % k != ty % k)
        {
            puts("No");
            continue;
        }
        h = sx + (n - sx) / k * k;
        //printf("q %d h %d\n", query(min(sy, ty), max(sy, ty)), h);
        puts(query(min(sy, ty), max(sy, ty)) < h ? "Yes" : "No");
    }
    return 0;
}