/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;

const int inf = 0x3f3f3f3f3f;
const int maxn = 1e6 + 10;
int n, m, id[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> pre_min(n + 1, vector<int>(m + 2));
    vector<vector<int>> pre_max(n + 1, vector<int>(m + 2));
    vector<vector<int>> suf_min(n + 1, vector<int>(m + 2));
    vector<vector<int>> suf_max(n + 1, vector<int>(m + 2));
    vector<int> pre_l(n + 2), pre_r(n + 2), suf_l(n + 2), suf_r(n + 2);    
    vector<char> ans(n + 1);
    int cnt = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        id[i] = i;
        pre_min[i][0] = inf, pre_max[i][0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &x);
            pre_min[i][j] = std::min(pre_min[i][j - 1], x);
            pre_max[i][j] = std::max(pre_max[i][j - 1], x);
            a[i][j] = x;
        }
        suf_min[i][m + 1] = inf, suf_max[i][m + 1] = 0;
        for (int j = m; j > 0; --j)
        {
            suf_min[i][j] = std::min(suf_min[i][j + 1], a[i][j]);
            suf_max[i][j] = std::max(suf_max[i][j + 1], a[i][j]);
        }
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return a[x][1] < a[y][1];});
    pre_r[0] = inf, suf_l[n + 1] = inf; 
    bool flag = false;
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            pre_l[j] = std::max(pre_l[j - 1], pre_max[id[j]][i]);
            pre_r[j] = std::min(pre_r[j - 1], suf_min[id[j]][i + 1]);
        }
        for (int j = n; j > 0; --j)
        {
            suf_l[j] = std::min(suf_l[j + 1], pre_min[id[j]][i]);
            suf_r[j] = std::max(suf_r[j + 1], suf_max[id[j]][i + 1]);
        }
        for (int j = 1; j < n; ++j)
        {
            flag |= ((suf_l[j + 1] > pre_l[j]) & (suf_r[j + 1] < pre_r[j]));
            if (flag)
            {
                for (int k = 1; k <= j; ++k)
                    ans[id[k]] = 'B';
                for (int k = j + 1; k <= n; ++k)
                    ans[id[k]] = 'R';
                puts("YES");
                for (int k = 1; k <= n; ++k)
                    putchar(ans[k]);
                printf(" %d\n", i);
                return;
            }
        }
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}