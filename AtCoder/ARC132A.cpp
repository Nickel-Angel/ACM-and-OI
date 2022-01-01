/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, r[maxn], c[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", r + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    int q, x, y;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &x, &y);
        x = r[x], y = c[y];
        //printf("%d %d\n", x, y);
        printf("%c", ".#"[x + y >= n + 1]);
    }
    return 0;
}