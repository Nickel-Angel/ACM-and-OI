#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3e5 + 10;
int n, head[maxn], to[maxn << 1], next[maxn << 1], tot;
int f[maxn][2], depth[maxn], g[maxn], bound;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    depth[u] = depth[pre] + 1;
    bound = std::max(bound, depth[u]);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
        if (f[v][0] + 1 > f[u][0])
        {
            f[u][1] = f[u][0];
            f[u][0] = f[v][0] + 1;
        }
        else if (f[v][0] + 1 > f[u][1])
            f[u][1] = f[v][0] + 1;
    }
    if (f[u][1] + depth[u] > 1)
        g[f[u][1] + depth[u] - 1] = std::max(g[f[u][1] + depth[u] - 1], (f[u][0] + f[u][1] + 1) / 2);
}   

inline void solve()
{
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(head, 0, sizeof(head));
    tot = 0, bound = 0;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    --bound;
    for (int i = bound - 1; i >= 0; --i)
        g[i] = std::max(g[i], g[i + 1]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (g[ans] + i > ans)
        {
            printf("update %d %d %d\n", g[ans], i, ans);
            ++ans;
        }
        printf("%d%c", std::min(ans, bound), " \n"[i == n]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}