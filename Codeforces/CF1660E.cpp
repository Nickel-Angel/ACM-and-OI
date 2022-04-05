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

int n;
char s[2010][2010];

inline void solve()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i]);
        for (int j = 0; j < n; ++j)
            tot += (s[i][j] == '1');
    }
    int cnt = 0;
    for (int j = 0, tmp; j < n; ++j)
    {
        tmp = 0;
        for (int i = 0; i < n; ++i)
            tmp += (s[i + 1][(j + i) % n] == '1');
        cnt = max(cnt, tmp);
    }
    printf("%d\n", tot - cnt + n - cnt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}