/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int dx[] = {-1, -1};
const int dy[] = {-1, 1};
int n, m, k;
char s[30][30];
bool vis[30][30];

inline int calc(int x, int y)
{
    int cnt[2] = {0, 0};
    int nx = x + dx[0], ny = y + dy[0];
    while (s[nx][ny] == '*')
    {
        ++cnt[0];
        nx += dx[0], ny += dy[0];
    }
    nx = x + dx[1], ny = y + dy[1];
    while (s[nx][ny] == '*')
    {
        ++cnt[1];
        nx += dx[1], ny += dy[1];
    }
    return std::min(cnt[0], cnt[1]);
}

inline void tick(int x, int y, int d)
{
    vis[x][y] = true;
    int nx = x + dx[0], ny = y + dy[0];
    for (int i = 0; i < d; ++i, nx += dx[0], ny += dy[0])
        vis[nx][ny] = true;
    nx = x + dx[1], ny = y + dy[1];
    for (int i = 0; i < d; ++i, nx += dx[1], ny += dy[1])
        vis[nx][ny] = true;
}

inline void solve()
{
    memset(vis, false, sizeof(vis));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == '*')
            {
                int d = calc(i, j);
                if (d < k)
                    continue;
                tick(i, j, d);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == '*' && !vis[i][j])
            {
                puts("NO");
                return;
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