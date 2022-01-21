/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using std::pair;

typedef pair<int, int> P;

const int maxn = 1e5 + 10;
int n, deg[maxn];
std::vector<int> e[maxn], ord, ans;
std::map<P, int> id;

void dfs(int u, int pre)
{
    for (int v : e[u])
    {
        if (v == pre)
            continue;
        ord.push_back(id[P(v, u)]);
        dfs(v, u);
    }
}

inline void solve()
{
    scanf("%d", &n);
    id.clear(), ord.clear();
    for (int i = 1; i <= n; ++i)
    {
        deg[i] = 0;
        e[i].clear();
    }
    bool flag = false;
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
        ++deg[u], ++deg[v];
        id[P(u, v)] = i - 1;
        id[P(v, u)] = i - 1;
        if (deg[u] > 2 || deg[v] > 2)
            flag = true;
    }
    if (flag)
    {
        puts("-1");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] == 1)
        {
            dfs(i, 0);
            break;
        }
    }
    ans = std::vector<int>(n - 1, 0);
    int x = 2;
    for (int i : ord)
    {
        ans[i] = x;
        x = 5 - x;    
    }
    for (int i : ans)
        printf("%d ", i);
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