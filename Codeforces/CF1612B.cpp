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

int n, a, b;
bool vis[110];

inline void solve()
{
    scanf("%d%d%d", &n, &a, &b);
    memset(vis, false, sizeof(vis));
    if (a <= n / 2 && b > n / 2 || (a == n / 2 + 1 && b == n / 2))
    {
        printf("%d ", a);
        vis[a] = true;
        int flag = 0;
        for (int i = n; i > n / 2 + 1; --i)
        {
            if (i == b)
                flag = -1;
            vis[i + flag] = true;
            printf("%d ", i + flag);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
                printf("%d ", i);
        }
        puts("");
    }
    else
        puts("-1");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}