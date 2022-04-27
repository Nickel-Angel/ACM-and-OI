/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e5 + 10;
int n, m, a[maxn], b[maxn], c[maxn], ans[maxn];
std::vector<int> v[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        v[i].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        if (a[i] != b[i])
            v[b[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", c + i);
    int pos = 0;
    if (!v[c[m]].empty())
    {
        pos = v[c[m]].back();
        v[c[m]].pop_back();
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (b[i] == c[m])
                pos = i;
        }
    }
    if (!pos)
    {
        puts("NO");
        return;
    }
    ans[m] = pos;
    for (int i = m - 1; i > 0; --i)
    {
        if (!v[c[i]].empty())
        {
            ans[i] = v[c[i]].back();
            v[c[i]].pop_back();
        }
        else
            ans[i] = pos;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i].size())
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for (int i = 1; i <= m; ++i)
        printf("%d%c", ans[i], " \n"[i == m]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}