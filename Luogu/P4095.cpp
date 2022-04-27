/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::max;
using std::min;

const int maxn = 3e5 + 10;
int n, q, e[maxn], v[1010], c[1010], p[1010], ans[maxn], f[15][1010];
std::vector<int> pos[1010];

inline void calc(int d, int i)
{
    static int q[1010][2];
    for (int j = 0, cur, L, R; j < v[i]; ++j)
    {
        L = 1, R = 0;
        for (int k = 0; k <= (1000 - j) / v[i]; ++k)
        {
            cur = f[d][j + k * v[i]] - k * c[i];
            while (L <= R && cur >= q[R][0])
                --R;
            q[++R][0] = cur, q[R][1] = k;
            while (L <= R && q[L][1] < k - p[i])
                ++L;
            f[d][j + k * v[i]] = max(f[d][j + k * v[i]], q[L][0] + k * c[i]);
        }
    }
}

void solve(int d, int l, int r)
{
    if (l == r)
    {
        for (int i : pos[l])
            ans[i] = f[d - 1][e[i]];
        return;
    }
    int mid = (l + r) >> 1;
    memcpy(f[d], f[d - 1], sizeof(f[d]));
    for (int i = mid + 1; i <= r; ++i)
        calc(d, i);
    solve(d + 1, l, mid);
    memcpy(f[d], f[d - 1], sizeof(f[d]));
    for (int i = l; i <= mid; ++i)
        calc(d, i);
    solve(d + 1, mid + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", v + i, c + i, p + i);
    scanf("%d", &q);
    for (int i = 1, id; i <= q; ++i)
    {
        scanf("%d%d", &id, e + i);
        pos[id + 1].push_back(i);
    }
    solve(1, 1, n);
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}