/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 1e6 + 10;
int n, m;
char s[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    vector<bool> key(m + 1);
    vector<int> sum(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; ++j)
            grid[i][j] = s[j];
    }
    sum[0] = 0;
    for (int j = 1; j < m; ++j)
    {
        for (int i = 1; i < n; ++i)
        {
            if (grid[i + 1][j] == 'X' && grid[i][j + 1] == 'X')
            {
                key[j] = true;
                break;
            }
        }
        sum[j] = sum[j - 1] + key[j];
    }
    int q, l, r;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        puts(sum[l - 1] == sum[r - 1] ? "YES" : "NO");
    }
    return 0;
}