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
int n, pre[maxn], cur[26], f[maxn][2];
char s[maxn];

inline void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(cur, 0, sizeof(cur));
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = cur[s[i] - 'a'];
        cur[s[i] - 'a'] = i;
    }
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0, f[1][1] = 1;
    int best = 0;
    for (int i = 2; i <= n; ++i)
    {
        f[i][0] = best + i - 1;
        f[i][1] = pre[i] ? f[pre[i]][0] + i - pre[i] - 1 : i;
        f[i][1] = min(f[i][1], best + i);
        best = min(best, f[i][1] - i);
    }
    printf("%d\n", f[n][1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}