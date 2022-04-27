/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using std::pair;
using std::array;
using std::vector;

typedef pair<int, int> P;

const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, -1, -1, 1, 1};
int n, m, c[1010][1010];
bool vis[1010][1010];
vector<array<int, 3>> ans;

inline int check(int i, int j)
{
    int key = 0;
    if (!vis[i][j])
        key = c[i][j];
    if (!vis[i + 1][j])
    {
        if (!key)
            key = c[i + 1][j];
        else if (c[i + 1][j] != key)
            return 0;
    }
    if (!vis[i][j + 1])
    {
        if (!key)
            key = c[i][j + 1];
        else if (c[i][j + 1] != key)
            return 0;
    }
    if (!vis[i + 1][j + 1])
    {
        if (!key)
            key = c[i + 1][j + 1];
        else if (c[i + 1][j + 1] != key)
            return 0;
    }
    return key;
}

void bfs()
{
    std::queue<P> q;
    for (int i = 1, key; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            key = check(i, j);
            if (key)
            {
                ans.push_back({i, j, key - 1});
                q.push(P(i, j));
                vis[i][j] = true, vis[i + 1][j] = true;
                vis[i][j + 1] = true, vis[i + 1][j + 1] = true;
            }
        }
    }
    int x, y;
    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0, nx, ny, key; i < 8; ++i)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx >= n || ny >= m)
                continue;
            key = check(nx, ny);
            if (key)
            {
                ans.push_back({nx, ny, key - 1});
                q.push(P(nx, ny));
                vis[nx][ny] = true, vis[nx][ny + 1] = true;
                vis[nx + 1][ny] = true, vis[nx + 1][ny + 1] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", c[i] + j);
            ++c[i][j];
        }
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!vis[i][j])
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%zu", ans.size());
    for (int i = (int)ans.size() - 1; i >= 0; --i)
    {
        puts("");
        printf("%d %d %d", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}