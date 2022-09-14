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

int n, x, y, z, a[1010], b[1010], id[3][1010];
bool vis[1010];

int main()
{
    scanf("%d%d%d%d", &n, &x, &y, &z);
    for (int i = 1; i <= n; ++i)
    {
        id[0][i] = i, id[1][i] = i, id[2][i] = i;
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    sort(id[0] + 1, id[0] + n + 1, [&](int x, int y){return a[x] == a[y] ? x < y : a[x] > a[y];});
    sort(id[1] + 1, id[1] + n + 1, [&](int x, int y){return b[x] == b[y] ? x < y : b[x] > b[y];});
    sort(id[2] + 1, id[2] + n + 1, [&](int x, int y){return a[x] + b[x] == a[y] + b[y] ? x < y : a[x] + b[x] > a[y] + b[y];});
    for (int i = 1; i <= x; ++i)
        vis[id[0][i]] = true;
    for (int i = 1; i <= min(n, y); ++i)
    {
        if (vis[id[1][i]])
            ++y;
        vis[id[1][i]] = true;
    }
    for (int i = 1; i <= min(n, z); ++i)
    {
        if (vis[id[2][i]])
            ++z;
        vis[id[2][i]] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            printf("%d\n", i);
    }
    return 0;
}