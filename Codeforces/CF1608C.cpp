/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], id[maxn], ans[maxn];
std::vector<int> e[maxn];

void dfs(int u)
{
    if (ans[u])
        return;
    ans[u] = 1;
    for (int v : e[u])
        dfs(v);
}

inline void solve()
{
    scanf("%d", &n);
    int S = 0;
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
        ans[i] = 0;
        scanf("%d", a + i);
        if (a[S] < a[i])
            S = i;
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y){return a[x] < a[y];});
    for (int i = 1; i < n; ++i)
        e[id[i]].push_back(id[i + 1]);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y){return b[x] < b[y];});
    for (int i = 1; i < n; ++i)
        e[id[i]].push_back(id[i + 1]);
    dfs(S);
    for (int i = 1; i <= n; ++i)
        printf("%d", ans[i]);
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