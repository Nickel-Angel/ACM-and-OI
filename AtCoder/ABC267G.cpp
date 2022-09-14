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

const int p = 998244353;
int n, m, a[5010], cnt[5010], f[5010][5010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    ++m;
    sort(a + 1, a + n + 1);
    int tot = 1, cur = a[1];
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != cur)
        {
            cur = a[i];
            tot = 0;
        }
        else
            ++tot;
        for (int j = 1; j <= m; ++j)
        {
            f[i][j] = (1ll * (i - j + 1) * f[i - 1][j - 1] % p + 1ll * (i - tot) * f[i - 1][j] % p) % p;
            printf("%d%c", f[i][j], " \n"[j == m]);
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}