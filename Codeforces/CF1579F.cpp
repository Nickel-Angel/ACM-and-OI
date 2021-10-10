/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
bool vis[maxn];
int n, d, a[maxn];

inline void solve()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        vis[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vis[i])
            continue;
        int cur = i, len = 0, tot = 0, res = 0, ring = 0;
        do
        {
            vis[cur] = true;
            if (a[cur] == 0)
            {
                res = std::max(res, len);
                len = 0;
            }
            else
            {
                ++len;
                if (ring == tot)
                    ++ring;
            }
            ++tot;
            cur = (cur + d) % n;
        } while(cur != i);
        if (ring == tot)
        {
            puts("-1");
            return;
        }
        else
            res = std::max(res, len + ring);
        ans = std::max(ans, res);
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}