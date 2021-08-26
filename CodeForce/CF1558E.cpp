/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 1010;
bool vis[maxn], ext[maxn];
int n, m, head[maxn], to[maxn << 2], next[maxn << 2], tot = 0;
int a[maxn], b[maxn], pre[maxn];
long long p[maxn];
std::queue<int> q;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline bool check(long long power)
{
    bool res = false;
    memset(vis, false, sizeof(vis));
    vis[1] = true, vis[0] = true;
    while (!res)
    {
        while (!q.empty())
            q.pop();
        for (int i = 1; i <= n; ++i)
        {
            ext[i] = vis[i];
            pre[i] = 0;
            if (vis[i])
            {
                q.push(i);
                p[i] = power;
            }
            else
                p[i] = 0;
        }
        bool route = false;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = head[u], v; c; c = next[c])
            {
                v = to[c];
                if ((vis[u] && vis[v]) || p[u] <= a[v] || v == pre[u])
                    continue;
                if (ext[v])
                {
                    route = true;
                    while (!vis[u])
                    {
                        vis[u] = true;
                        power += b[u];
                        u = pre[u];
                    }
                    while (!vis[v])
                    {
                        vis[v] = true;
                        power += b[v];
                        v = pre[v];
                    }
                    break;
                }
                ext[v] = true, pre[v] = u;
                p[v] = p[u] + b[v];
                q.push(v);
            }
            if (route)
                break;
        }
        if (!route)
            return false;
        res = true;
        for (int i = 1; i <= n; ++i)
            res &= vis[i];
    }
    return true;
}

int main()
{
    int t, s, e;
    scanf("%d\n", &t);
    while (t--)
    {
        memset(head, 0, sizeof(head));
        tot = 0;
        s = 1, e = 0;
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n; ++i)
        {
            scanf("%d", a + i);
            e = max(e, a[i]);
        }
        for (int i = 2; i <= n; ++i)
            scanf("%d", b + i);
        for (int i = 1, u, v; i <= m; ++i)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        e += 2;
        int ans = e;
        while (s <= e)
        {
            int mid = (s + e) >> 1;
            if (check(mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}