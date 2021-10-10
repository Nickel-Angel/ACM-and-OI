/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e3 + 10;
int n, a[maxn], pre[maxn], pos[maxn], f[maxn][maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        pos[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int l = 1, r = i; r <= n; ++l, ++r)
        {
            f[l][r] = f[l][r - 1] + (a[r] != a[r - 1]);
            for (int j = r; j >= l; j = pre[j])
                f[l][r] = std::min(f[l][r], f[l][j] + f[j + 1][r]);
        }
    }
    printf("%d\n", f[1][n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}