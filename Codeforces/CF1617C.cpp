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

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], cnt, vis[maxn];

inline void solve(const int &t)
{
    scanf("%d", &n);
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] > n || vis[a[i]] == t)
            b[++cnt] = min(n, a[i] - (a[i] / 2) - 1);
        else
            vis[a[i]] = t;
    }
    sort(b + 1, b + cnt + 1);
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (vis[i] == t)
            continue;
        if (i <= b[j])
        {
            vis[i] = t;
            ++j;
        }
        else
        {
            puts("-1");
            return;
        }
    }
    printf("%d\n", cnt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve(t + 1);
    return 0;
}