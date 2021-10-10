/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int a = 5, b = 4;
int n, m, sum[410][410];
char rec[410][410];

inline int getsum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", rec[i] + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (rec[i][j] ^ 48);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i + 3; j <= m; ++j)
        {
            int cur = 0x3f3f3f3f;
            for (int k = 5; k <= n; ++k)
            {
                cur += (rec[k - 1][i] == '0') + (rec[k - 1][j] == '0');
                cur += getsum(k - 1, i + 1, k - 1, j - 1);
                cur = min(cur, (j - i - 1) - getsum(k - 4, i + 1, k - 4, j - 1) + 3 - getsum(k - 3, i, k - 1, i) + 3 - getsum(k - 3, j, k - 1, j) + getsum(k - 3, i + 1, k - 1, j - 1));
                ans = min(ans, cur + (j - i - 1) - getsum(k, i + 1, k, j - 1));
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}