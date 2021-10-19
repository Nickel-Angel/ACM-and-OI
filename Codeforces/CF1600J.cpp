/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int n, m, a[1010][1010], cnt[1000010], cur;
bool vis[1010][1010];

void dfs(int x, int y)
{
    if (x <= 0 || x > n || y <= 0 || y > m)
        return;
    vis[x][y] = true;
    ++cnt[cur];
    for (int i = 0; i < 4; ++i)
    {
        if (vis[x + dx[i]][y + dy[i]])
            continue;
        if (!(a[x][y] & (1 << i)))
            dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", a[i] + j);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (vis[i][j])
                continue;
            ++cur;
            dfs(i, j);
        }
    }
    std::sort(cnt + 1, cnt + cur + 1, std::greater<int>());
    for (int i = 1; i <= cur; ++i)
        printf("%d ", cnt[i]);
    return 0;
}