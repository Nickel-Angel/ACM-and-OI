/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1010;
const int maxm = 10010;
int T, n, m, head[maxn], to[maxm << 1], next[maxm << 1], tot;
bool vis[maxn], ans;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

struct frac
{
    bool flag;
    int x, y;

    frac() {flag = false;}

    frac(int x, int y): x(x), y(y) {flag = false;}

    frac(int x, int y, bool flag): x(x), y(y), flag(flag) {}

    frac operator * (int z)
    {
        frac res = frac(x, y, flag);
        if (z < 0)
        {
            res.flag ^= 1;
            z = -z;
        }
        res.x *= z;
        int d = gcd(res.x, res.y);
        res.x /= d, res.y /= d;
        return res;
    }

    frac operator / (int z)
    {
        frac res = frac(x, y, flag);
        if (z < 0)
        {
            res.flag ^= 1;
            z = -z;
        }
        res.y *= z;
        int d = gcd(res.x, res.y);
        res.x /= d, res.y /= d;
        return res;
    }

    inline bool operator != (const frac &rhs)
    {
        return x != rhs.x || y != rhs.y || flag != rhs.flag;
    }
};

frac val[maxm << 1], speed[maxn];

inline void add_edge(int u, int v, const frac &w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u)
{
    vis[u] = true;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (vis[v])
        {
            if (speed[u] / val[c].x != speed[v] / val[c].y)
            {    
                ans = false;
                return;        
            }
            continue;
        }
        speed[v] = (speed[u] / val[c].x) * val[c].y;
        dfs(v);
        if (!ans) return;
    }
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        memset(head, 0, sizeof(head)), tot = 0;
        memset(vis, false, sizeof(vis));
        ans = true;
        scanf("%d%d", &n, &m);
        for (int i = 1, u, v, x, y; i <= m; ++i)
        {
            scanf("%d%d%d%d", &u, &v, &x, &y);
            add_edge(u, v, frac(x, y)), add_edge(v, u, frac(y, x));
        }
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i]) continue;
            speed[i] = frac(1, 1);
            dfs(i);
            if (!ans) break;
        }
        printf("Case #%d: ", t);
        puts(ans ? "Yes" : "No");
    }
    return 0;
}