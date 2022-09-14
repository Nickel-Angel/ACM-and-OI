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

int n, x, y;
ll f[20][2];

ll dfs(int level, int color)
{
    if (f[level][color] != -1)
        return f[level][color];
    ll &res = f[level][color];
    if (level == 1)
    {
        res = color;
        return res;
    }
    if (color == 0)
        res = dfs(level - 1, 0) + x * dfs(level, 1);
    else
        res = dfs(level - 1, 0) + y * dfs(level - 1, 1);
    return res;
}

int main()
{
    memset(f, -1, sizeof(f));   
    scanf("%d%d%d", &n, &x, &y);
    printf("%lld\n", dfs(n, 0));
    return 0;
}