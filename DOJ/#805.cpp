/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
int n, m, q, head[maxn], to[maxn << 1], next[maxn << 1], val[maxn << 1], tot;
int par[maxn][21], f[maxn][21], depth[maxn];

class Union_Find_Set
{
  private:
    int par[maxn], size[maxn];

  public:
    inline void init(int bound)
    {
        for (int i = 1; i <= bound; ++i)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    inline bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            std::swap(x, y);
        size[x] += size[y];
        par[y] = x;
        return true;
    }
}S;

struct edge
{
    int from, to, val;

    bool operator < (const edge &rhs) const
    {
        return val < rhs.val;
    }
}e[maxm];

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    par[u][0] = pre, depth[u] = depth[pre] + 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        f[v][0] = val[c];
        dfs(v, u);
    }
}

inline int query(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    int ans = 0;
    for (int i = 20; i >= 0; --i)
    {
        if (depth[par[x][i]] >= depth[y])
        {
            ans = std::max(ans, f[x][i]);
            x = par[x][i];
        }
    }
    if (x == y)
        return ans;
    for (int i = 20; i >= 0; --i)
    {
        if (par[x][i] != par[y][i])
        {
            ans = std::max({ans, f[x][i], f[y][i]});
            x = par[x][i];
            y = par[y][i];
        }
    }
    ans = std::max({ans, f[x][0], f[y][0]});
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].val);
    std::sort(e + 1, e + m + 1);
    S.init(n);
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        if (S.unite(e[i].from, e[i].to))
        {
            add_edge(e[i].from, e[i].to, e[i].val);
            add_edge(e[i].to, e[i].from, e[i].val);
            ++cnt;
            if (cnt == n - 1)
                break;
        }
    }
    dfs(1, 0);
    for (int j = 1; j <= 20; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
            f[i][j] = std::max(f[i][j - 1], f[par[i][j - 1]][j - 1]);
        }
    }
    scanf("%d", &q);
    int x, y;
    while (q--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}