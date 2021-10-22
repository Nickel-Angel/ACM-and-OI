/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n;
char grid[5][110];
bool vis[5][110];

void dfs(int x, int y)
{
    if (x <= 0 || y <= 0 || x > 2 || y > n || grid[x][y] == '1' || vis[x][y])
        return;
    vis[x][y] = true;
    dfs(x - 1, y - 1), dfs(x - 1, y), dfs(x - 1, y + 1);
    dfs(x, y - 1), dfs(x, y + 1);
    dfs(x + 1, y - 1), dfs(x + 1, y), dfs(x + 1, y + 1);
}

inline void solve()
{
    scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= 2; ++i)
        scanf("%s", grid[i] + 1);
    dfs(1, 1);
    puts(vis[2][n] ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}