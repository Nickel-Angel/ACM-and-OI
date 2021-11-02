/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

int n;
std::vector<int> dfn, e[1010];

void dfs(int u, int pre)
{
    dfn.push_back(u);
    for (int v : e[u])
    {
        if (v == pre)
            continue;
        dfs(v, u);
        dfn.push_back(u);
    }
}

inline int query(int l, int r)
{
    std::set<int> s;
    for (int i = l - 1; i < r; ++i)
        s.insert(dfn[i]);
    printf("? %zu ", s.size());
    for (int u : s)
        printf("%d ", u);
    puts(""), fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(1, 0);
    int l = 1, r = 2 * n - 1, x = query(1, 2 * n - 1);
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if (query(l, mid) == x)
            r = mid;
        else
            l = mid;
    }
    printf("! %d %d\n", dfn[l - 1], dfn[r - 1]);
    fflush(stdout);
    return 0;
}