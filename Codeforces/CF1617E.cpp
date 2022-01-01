/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

typedef long long ll;

using std::map;

const int maxn = 1e7 + 10;
int n, depth[maxn], key[maxn][2], rev[maxn];
int head[maxn], to[maxn], next[maxn], tot, par[maxn];
int x, y, anc, ans;
map<int, int> p, id;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline int getpar(int u)
{
    for (int i = 0; i <= 31; ++i)
    {
        if (u <= (1ll << i))
            return (1ll << i) - u;
    }
    return -1;
}

inline int dis(int x, int y, int anc)
{
    return x && y ? depth[x] - depth[anc] + depth[y] - depth[anc] : 0;
}

void dfs(int u)
{
    depth[u] = depth[par[u]] + 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs(v);
        if (depth[key[u][0]] < depth[key[v][0]])
        {
            key[u][1] = key[u][0];
            key[u][0] = key[v][0];
        }
        else if (depth[key[u][1]] < depth[key[v][0]])
            key[u][1] = key[v][0];
    }
    if (id.count(rev[u]) && !key[u][0])
        key[u][0] = u;
    if (id.count(rev[u]) && !key[u][1])
        key[u][1] = u;
    if (dis(x, y, anc) < dis(key[u][0], key[u][1], u))
    {
        x = key[u][0], y = key[u][1], anc = u;
        ans = dis(key[u][0], key[u][1], u);
    }
}

int main()
{
    scanf("%d", &n);
    int cnt = 0;
    p[0] = ++cnt;
    for (int i = 1, x, y; i <= n; ++i)
    {
        scanf("%d", &x);
        id[x] = i;
        if (p.count(x))
            continue;
        while (x)
        {
            p[x] = ++cnt;
            rev[cnt] = x;
            y = getpar(x);
            if (p.count(y))
            {
                par[cnt] = p[y];
                add_edge(par[cnt], cnt);
                break;
            }
            par[cnt] = cnt + 1;
            add_edge(par[cnt], cnt);
            x = y;
        }
    }
    dfs(1);
    printf("%d %d %d\n", id[rev[x]], id[rev[y]], ans);
    return 0;
}