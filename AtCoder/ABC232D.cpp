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

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::pair;

typedef pair<int, int> P;

int n, m, dis[110][110], ans;
char s[110][110];

void bfs()
{
    std::queue<P> q;
    q.push(P(1, 1));
    dis[1][1] = 1, ans = 1;
    int x, y;
    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        ans = max(ans, dis[x][y]);
        q.pop();
        if (x < n && s[x + 1][y] != '#' && dis[x + 1][y] < dis[x][y] + 1)
        {
            dis[x + 1][y] = dis[x][y] + 1; 
            q.push(P(x + 1, y));
        }
        if (y < m && s[x][y + 1] != '#' && dis[x][y + 1] < dis[x][y] + 1)
        {
            dis[x][y + 1] = dis[x][y] + 1;
            q.push(P(x, y + 1));
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i] + 1);
    bfs();
    printf("%d\n", ans);
    return 0;
}