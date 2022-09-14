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

const int maxn = 1e5 + 10;
int n, t[maxn], x[maxn], a[maxn];
ll f[maxn][5];
vector<int> sunke[maxn];

int main()
{
    scanf("%d", &n);
    int T = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", t + i, x + i, a + i);
        T = max(T, t[i]);
        sunke[t[i]].push_back(i);
    }
    for (int i = 0; i <= T; ++i)
    {
        for (int j = 0; j < 5; ++j)
            f[i][j] = -1e15;
    }
    f[0][0] = 0;
    for (int i = 1; i <= T; ++i)
    {
        for (int j = 0; j < 5; ++j)
            f[i][j] = f[i - 1][j];
        for (int id : sunke[i])
        {
            for (int j = 0; j < 5; ++j)
            {
                if (i >= abs(j - x[id]))
                    f[i][x[id]] = max(f[i][x[id]], f[i - max(1, abs(j - x[id]))][j] + a[id]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 5; ++i)
        ans = max(ans, f[T][i]);
    printf("%lld\n", ans);
    return 0;
}