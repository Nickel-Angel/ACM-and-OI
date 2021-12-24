/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 1e4 + 10;
int n, a[maxn], ans[maxn];

inline int query(int a, int b, int c)
{
    printf("? %d %d %d\n", a, b, c);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res ^ 1;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        ans[i] = 0;
    int x, y;
    for (int i = 1; i <= n; i += 3)
    {
        a[i] = query(i, i + 1, i + 2);
        if (a[i] == 1)
            x = i;
        else
            y = i;
    }
    int pos[2] = {0, 0};
    if (query(x, x + 1, y) && query(x, x + 1, y + 1))
        pos[1] = x;
    else
        pos[1] = x + 2;
    if (query(y, y + 1, x) || query(y, y + 1, x + 1) || query(y, y + 1, x + 2))
        pos[0] = y + 2;
    else
        pos[0] = y;
    int cnt = 0;
    for (int i = 1; i <= n; i += 3)
    {
        if (a[i])
        {
            ans[i] = ans[i + 1] = ans[i + 2] = 1;
            int t1 = query(pos[0], i, i + 1), t2 = query(pos[0], i + 1, i + 2);
            if (t1 == 0 && t2 == 0)
                ans[i + 1] = 0;
            else if (t1 == 0)
                ans[i] = 0;
            else if (t2 == 0)
                ans[i + 2] = 0;
        }
        else
        {
            int t1 = query(pos[1], i, i + 1), t2 = query(pos[1], i + 1, i + 2);
            if (t1 == 1 && t2 == 1)
                ans[i + 1] = 1;
            else if (t1 == 1)
                ans[i] = 1;
            else if (t2 == 1)
                ans[i + 2] = 1;
        }
        cnt += ans[i] + ans[i + 1] + ans[i + 2];
    }
    printf("! %d", cnt);
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
            printf(" %d", i);
    }
    puts("");
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}