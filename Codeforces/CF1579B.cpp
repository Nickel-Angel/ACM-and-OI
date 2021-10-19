/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

int n, a[60], b[60], help[60];
std::map<int, int> rank;
std::vector<int> ans[3];

inline void offset(int l, int r, int d)
{
    int k = r - l + 1;
    for (int i = 0; i < k; ++i)
        help[l + (i + d) % k] = a[l + i];
    for (int i = l; i <= r; ++i)
        a[i] = help[i];
    ans[0].push_back(l), ans[1].push_back(r), ans[2].push_back(k - d);
}

inline void solve()
{
    rank.clear();
    for (int i = 0; i < 3; ++i)
        ans[i].clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    int cnt = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= cnt; ++i)
        rank[b[i]] = i;
    int cur = 1;
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (rank[a[j]] != i)
                continue;
            if (j != cur)
                offset(cur, j, 1);
            ++cur;
        }
    }
    printf("%u\n", ans[0].size());
    for (unsigned i = 0; i < ans[0].size(); ++i)
        printf("%d %d %d\n", ans[0][i], ans[1][i], ans[2][i]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}