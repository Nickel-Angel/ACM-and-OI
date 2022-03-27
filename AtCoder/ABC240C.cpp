/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

int n, a[110], b[110], x;
std::bitset<10010> vis;

int main()
{
    scanf("%d%d", &n, &x);
    vis[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a + i, b + i);
        vis = (vis << a[i]) | (vis << b[i]);
    }
    puts(vis[x] ? "Yes" : "No");
    return 0;
}