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

const int maxn = 1e6 + 10;
int n, w, a[310], f[maxn];

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] <= w)
            f[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] + a[j] > w)
                continue;
            f[a[i] + a[j]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            for (int k = j + 1; k <= n; ++k)
            {
                if (a[i] + a[j] + a[k] > w)
                    continue;
                f[a[i] + a[j] + a[k]] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= w; ++i)
        ans += f[i];
    printf("%d\n", ans);
    return 0;
}