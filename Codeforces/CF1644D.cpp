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
const int maxn = 2e5 + 10;
int n, m, k, q, x[maxn], y[maxn];
bool row[maxn], col[maxn];

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {   
        if (b & 1)
            res = 1ll * a * res % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

inline void solve()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= n; ++i)
        row[i] = false;
    for (int i = 1; i <= m; ++i)
        col[i] = false;
    for (int i = 1; i <= q; ++i)
        scanf("%d%d", x + i, y + i);
    int cnt = 0, r = 0, c = 0;
    for (int i = q; i > 0 && r < n && c < m; --i)
    {
        if (row[x[i]] && col[y[i]])
            continue;
        ++cnt, r += row[x[i]] ? 0 : 1, c += col[y[i]] ? 0 : 1;
        row[x[i]] = true, col[y[i]] = true;
    }
    printf("%d\n", power(k, cnt));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}