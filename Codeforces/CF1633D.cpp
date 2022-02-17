/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 1e6 + 10;
int n, k, b[1010], c[1010], dis[1010], f[maxn];
bool vis[1010];

inline void bfs()
{
    std::queue<int> q;
    q.push(1);
    dis[1] = 0;
    vis[1] = true;
    int x;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int l = 1, r; l <= x; l = r + 1)
        {
            r = x / (x / l);
            if (x + x / l > 1000 || vis[x + x / l])
                continue;
            dis[x + x / l] = dis[x] + 1;
            vis[x + x / l] = true;
            q.push(x + x / l);
        }
    }
}   

inline void solve()
{
    memset(f, 0, sizeof(f));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        b[i] = dis[b[i]];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    int tot = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        tot += b[i];
        for (int j = std::min(tot, k); j >= b[i]; --j)
        {
            f[j] = std::max(f[j], f[j - b[i]] + c[i]);
            ans = std::max(ans, f[j]);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    bfs();
    while (t--)
        solve();
    return 0;
}