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

int n, cnt_a[210], cnt_b[210], a[110], b[110];

inline void solve()
{
    memset(cnt_a, 0, sizeof(cnt_a));
    memset(cnt_b, 0, sizeof(cnt_b));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt_a[a[i] + 100];
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        ++cnt_b[b[i] + 100];
    }
    for (int i = 0; i <= 200; ++i)
    {
        if (cnt_a[i])
        {
            int x = cnt_b[i];
            cnt_b[i] -= min(x, cnt_a[i]);
            cnt_a[i] -= min(x, cnt_a[i]);
            if (cnt_a[i])
            {
                x = cnt_b[i + 1];
                cnt_b[i + 1] -= min(x, cnt_a[i]);
                cnt_a[i] -= min(x, cnt_a[i]);
            }
        }
    }
    bool flag = true;
    for (int i = 0; i <= 201; ++i)
        flag &= (cnt_a[i] == 0 && cnt_b[i] == 0);
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}