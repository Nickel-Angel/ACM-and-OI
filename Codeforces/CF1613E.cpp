/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::queue;
using std::pair;

typedef pair<int, int> P;

int n, m, Sx, Sy;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

inline void solve()
{
    cin >> n >> m;
    vector<string> grid(n + 1, "#");
    vector<vector<int>> w(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> grid[i];
        grid[i] = '#' + grid[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (grid[i][j] == '.')
            {
                if (i > 1)
                    ++w[i - 1][j];
                if (j > 1)
                    ++w[i][j - 1];
                if (i < n)
                    ++w[i + 1][j];
                if (j < m)
                    ++w[i][j + 1];
            }
            if (grid[i][j] == 'L')
            {
                Sx = i, Sy = j;
                if (i > 1)
                    ++w[i - 1][j];
                if (j > 1)
                    ++w[i][j - 1];
                if (i < n)
                    ++w[i + 1][j];
                if (j < m)
                    ++w[i][j + 1];
            }
        }
    }
    queue<P> q;
    q.push(P(Sx, Sy));
    int x, y, nx, ny;
    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (grid[nx][ny] != '.')
                continue;
            --w[nx][ny];
            if (w[nx][ny] > 1)
                continue;
            grid[nx][ny] = '+';
            q.push(P(nx, ny));
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}