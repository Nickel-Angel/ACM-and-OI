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

int n, m, r, c;
char s[60][60];

inline void solve()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    bool Rw = false, Cw = false, flag = false;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; ++j)
            flag |= (s[i][j] == 'B');
    }
    for (int i = 1; i <= n; ++i)
        Cw |= (s[i][c] == 'B');
    for (int i = 1; i <= m; ++i)
        Rw |= (s[r][i] == 'B');
    if (!flag)
    {
        puts("-1");
        return;
    }
    if (s[r][c] == 'B')
        puts("0");
    else if (Rw || Cw)
        puts("1");
    else
        puts("2");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}