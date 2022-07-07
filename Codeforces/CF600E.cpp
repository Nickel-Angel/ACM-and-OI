#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e5 + 10;
int n, c[maxn], head[maxn], to[maxn << 1], next[maxn << 1], tot;
int rev[maxn], dfn[maxn][2], size[maxn], son[maxn], cnt[maxn], key[maxn];
int tim, maxtime, keytag;
long long ans[maxn], sum;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u, int pre)
{
    size[u] = 1, dfn[u][0] = ++tim;
    rev[tim] = u;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs_son(v, u);
        size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
    dfn[u][1] = tim;
}

inline void add(int u)
{
    ++cnt[c[u]];
    if (cnt[c[u]] > maxtime)
    {
        maxtime = cnt[c[u]];
        sum = c[u];
        key[c[u]] = ++keytag;
    }
    else if (cnt[c[u]] == maxtime && key[c[u]] != keytag)
    {
        sum += c[u];
        key[c[u]] = keytag;
    }
}

void dfs_solve(int u, int pre, bool keep)
{
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre || v == son[u])
            continue;
        dfs_solve(v, u, false);
    }
    if (son[u])
        dfs_solve(son[u], u, true);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre || v == son[u])
            continue;
        for (int i = dfn[v][0]; i <= dfn[v][1]; ++i)
            add(rev[i]);
    }
    add(u);
    ans[u] = sum;
    if (!keep)
    {
        sum = 0, maxtime = 0;
        for (int i = dfn[u][0]; i <= dfn[u][1]; ++i)
            cnt[c[rev[i]]] = 0;
    }   
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", c + i);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs_son(1, 0);
    dfs_solve(1, 0, 1);
    for (int i = 1; i <= n; ++i)
        printf("%lld%c", ans[i], " \n"[i == n]);
    return 0;
}