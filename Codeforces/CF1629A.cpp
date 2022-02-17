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

int n, k, a[110], b[110], id[110];

inline void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return a[x] < a[y];});
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = 1; i <= n; ++i)
    {
        if (k >= a[id[i]])
            k += b[id[i]];
        else
            break;
    }
    printf("%d\n", k);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}