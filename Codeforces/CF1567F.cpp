/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <cstdio>
#include <cstring>
#include <vector>

#define color(u) (color[(u - 1) / m + 1][(u - 1) % m + 1])

using std::vector;

int n, m, help[5], cnt = 0, color[510][510];
char grid[510][510];
vector<int> e[510 * 510];

inline void undir_add(int u, int v)
{
    //printf("add %d %d\n", u, v);
    e[u].push_back(v);
    e[v].push_back(u);
}

inline int id(int i, int j)
{
    return (i - 1) * m + j;
}

inline bool check(int i, int j)
{
    if (grid[i - 1][j] == '.')
        help[++cnt] = id(i - 1, j);
    if (grid[i][j - 1] == '.')
        help[++cnt] = id(i, j - 1);
    if (grid[i + 1][j] == '.')
        help[++cnt] = id(i + 1, j);
    if (grid[i][j + 1] == '.')
        help[++cnt] = id(i, j + 1);
    return (cnt & 1) ? false : true;
}

void dfs(int u, int state)
{
    color(u) = state;
    //printf("%d [%d,%d] %d\n", u, (u - 1) / m + 1, (u - 1) % m + 1, state);
    for (auto v : e[u])
    {
        if (color(v) != -1)
            continue;
        dfs(v, 5 - state);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", grid[i] + 1);
    memset(color, -1, sizeof(color));
    for (int i = 2; i < n; ++i)
    {
        for (int j = 2; j < m; ++j)
        {
            if (grid[i][j] == '.')
                continue;
            cnt = 0;
            if (check(i, j))
            {
                if (cnt == 2)
                {
                    color[i][j] = 5;
                    undir_add(help[1], help[2]);
                }
                else if (cnt == 4)
                {
                    color[i][j] = 10;
                    undir_add(help[1], help[2]);
                    undir_add(help[2], help[3]);
                    undir_add(help[3], help[4]);
                    undir_add(help[4], help[1]);
                }
                else if (cnt == 0)
                    color[i][j] = 0;
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (color[i][j] == -1)
                dfs(id(i, j), 1);
            printf("%d%c", color[i][j], " \n"[j == m]);
        }
    }
    return 0;
}