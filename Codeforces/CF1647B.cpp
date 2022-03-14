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

int n, m, sum[110][110];
char s[110][110];
bool lock[110][110];

inline void solve()
{
    memset(lock, false, sizeof(lock));
    memset(s, 0, sizeof(s));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i] + 1);
    int x, y, u, l;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == '1' && !lock[i][j])
            {
                u = i - 1;
                while (s[u][j] == '1')
                    --u;
                ++u;
                l = j - 1;
                while (s[i][l] == '1')
                    --l;
                ++l;
                x = i + 1;
                while (s[x][j] == '1')
                    ++x;
                --x;
                y = j + 1;
                while (s[i][y] == '1')
                    ++y;
                --y;
                for (int k = u; k <= x; ++k)
                {
                    for (int p = l; p <= y; ++p)
                    {
                        if (s[k][p] == '0' || lock[k][p])
                        {
                            puts("NO");
                            return;
                        }
                        lock[k][p] = true;
                    }
                }
            }
        }
    }
    puts("YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}