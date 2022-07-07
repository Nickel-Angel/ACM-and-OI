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

int n, pos[110][20], vis[20];
char s[110][20];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i]);
        for (int j = 0; j < 10; ++j)
            pos[i][s[i][j] - '0'] = j; 
    }
    int ans = 10 * n, res;
    for (int i = 0; i < 10; ++i)
    {
        memset(vis, 0, sizeof(vis));
        res = 0;
        for (int j = 1; j <= n; ++j)
        {
            res = std::max(res, pos[j][i] + 10 * vis[pos[j][i]]);
            ++vis[pos[j][i]];
        }
        ans = std::min(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}