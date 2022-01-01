/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;

const int maxm = 1e4 + 10;
int n, m, x[20], val[maxm], p[maxm];
char s[20][maxm];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", x + i);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i]);
    vector<int> best, cur;
    int ans = -1, res;
    for (int i = 0; i < m; ++i)
        cur.push_back(i);
    for (int S = 0; S < (1 << n); ++S)
    {
        res = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (S & (1 << (i - 1)))
            {
                res += x[i];
                for (int j = 0; j < m; ++j)
                    val[j] -= (s[i][j] == '1');
            }
            else
            {
                res -= x[i];
                for (int j = 0; j < m; ++j)
                    val[j] += (s[i][j] == '1');
            }
        }
        std::sort(cur.begin(), cur.end(), [&](int x, int y){return val[x] < val[y];});
        for (int i = 0; i < m; ++i)
        {
            res += val[cur[i]] * (i + 1);
            val[cur[i]] = 0;
        }
        if (res > ans)
        {
            ans = res;
            best = cur;
        }
    }
    for (int i = 0; i < m; ++i)
        p[best[i]] = i + 1;
    for (int i = 0; i < m; ++i)
        printf("%d ", p[i]);
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}