/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int n, p[510];
int color[510][510];


bool dfs(int x, int y, int c, int cnt)
{
    color[x][y] = c;
    if (cnt == c)
        return true;
    for (int i = 0, nx, ny; i < 4; ++i)
    {
        nx = x + dx[i], ny = y + dy[i];
        if (nx < y || ny <= 0 || nx > n || ny > x || color[nx][ny])
            continue;
        return dfs(nx, ny, c, cnt + 1);
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    bool flag = true;
    for (int i = 1; i <= n; ++i)
        flag &= dfs(i, i, p[i], 1);
    if (!flag)
        puts("-1");
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                printf("%d%c", color[i][j], " \n"[j == i]);
            }
        }   
    }
    return 0;
}