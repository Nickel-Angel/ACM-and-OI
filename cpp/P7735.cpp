#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1e5 + 10;
int head[maxn], to[maxn], next[maxn], tot = 0;
int T, n, m, par[maxn], son[maxn], depth[maxn], size[maxn];
int top[maxn], rev_dfn[maxn], dfn[maxn], dfs_t, cur_time;

template<typename T1, typename T2>
T1 max(T1 x, T2 y)
{
    return x > y ? x : y;
}

template<typename T1, typename T2>
T1 min(T1 x, T2 y)
{
    return x < y ? x : y;
}

class Segtree
{
    #define lson u << 1
    #define rson u << 1 | 1
  private:
    int time[maxn << 2], sum[maxn << 2], tag_t[maxn << 2];
    bool tag_s[maxn << 2];
    
    inline void pushdown(int s, int e, int u)
    {
        tag_t[rson] = time[u], tag_t[lson] = tag_t[u];
        time[lson] = time[u], time[rson] = time[u];
        if (!tag_s[u]) return;
        int mid = (s + e) >> 1;
        sum[lson] = mid - s + 1, sum[rson] = e - mid;
        tag_s[lson] = true, tag_s[rson] = true;
        tag_s[u] = false;
    }

  public:
    void build(int s, int e, int u)
    {
        sum[u] = 0, time[u] = 0;
        tag_t[u] = 0, tag_s[u] = false;
        if (s == e) return;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);

    }

    void modify(int s, int e, int ql, int qr, int u)
    {
        if (ql <= s && e <= qr)
        {
            tag_s[u] = true;
            tag_t[u] = cur_time;
            sum[u] = e - s + 1;
            return;
        }
        pushdown(s, e, u);
        int mid = (s + e) >> 1;
        if (ql <= mid) modify(s, mid, ql, qr, lson);
        if (qr > mid) modify(mid + 1, e, ql, qr, rson);
        sum[u] = sum[lson] + sum[rson];
    }
    #undef lson
    #undef rson
}tree;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u, int pre)
{
    par[u] = pre;
    depth[u] = depth[pre] + 1;
    size[u] = 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre) continue;
        dfs_son(v, u);
        size[u] += size[v];
        if (size[v] > size[son[u]]) son[u] = v;
    }
}

void dfs_top(int u, int anc)
{
    dfn[u] = ++dfs_t;
    rev_dfn[dfs_t] = u;
    top[u] = anc;
    if (son[u]) dfs_top(son[u], anc);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == par[u] || v == son[u]) continue;
        dfs_top(v, v);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        dfs_t = 0, tot = 0;
        std::memset(head, 0, sizeof(head));
        std::memset(son, 0, sizeof(son));
        scanf("%d%d", &n, &m);
        for (int i = 0, u, v; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        dfs_son(1, 0), dfs_top(1, 1);
        tree.build(1, n, 1);
        int opt, a, b;
        for (cur_time = 1; cur_time <= m; ++cur_time)
        {
            scanf("%d%d%d", &opt, &a, &b);
            if (opt == 1)
            {

            }
            else
            {

            }
        }
    }
    return 0;
}