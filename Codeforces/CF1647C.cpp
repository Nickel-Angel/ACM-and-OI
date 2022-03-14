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

int n, m, q, ans[10010][4];
char s[110][110];

inline void solve()
{
    q = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i] + 1);
    if (s[1][1] == '1')
    {
        puts("-1");
        return;
    }
    for (int i = n; i > 0; --i)
    {
        for (int j = m; j > 1; --j)
        {
            if (s[i][j] == '1')
            {
                ans[++q][0] = i, ans[q][1] = j - 1;
                ans[q][2] = i, ans[q][3] = j;
            }
        }
        if (s[i][1] == '1')
        {
            ans[++q][0] = i - 1, ans[q][1] = 1;
            ans[q][2] = i, ans[q][3] = 1;
        }
    }
    printf("%d\n", q);
    for (int i = 1; i <= q; ++i)
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}