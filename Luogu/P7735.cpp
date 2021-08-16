/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using std::max;
using std::min;
using std::swap;

const int maxn = 1e5 + 10;
int head[maxn], to[maxn << 1], next[maxn << 1], tot = 0;
int T, n, m, par[maxn], son[maxn], depth[maxn], size[maxn];
int top[maxn], rev_dfn[maxn], dfn[maxn], dfs_t;

struct data
{
    int lc, rc, sum;

    data() {}

    data(int _lc, int _rc, int _sum)
    {
        lc = _lc, rc = _rc, sum = _sum;
    }
};

class Segtree
{
    #define lson u << 1
    #define rson u << 1 | 1
  private:
    int color[maxn << 2][2], sum[maxn << 2], lazy[maxn << 2];

    inline void pushdown(int s, int e, int u)
    {
        if (!lazy[u]) return;
        int mid = (s + e) >> 1;
        lazy[lson] = lazy[u], color[lson][0] = lazy[u], color[lson][1] = lazy[u];
        lazy[rson] = lazy[u], color[rson][0] = lazy[u], color[rson][1] = lazy[u];
        sum[lson] = mid - s, sum[rson] = e - mid - 1;
        lazy[u] = 0;
    }

  public:
    inline void build(int s, int e, int u)
    {
        color[u][0] = 0, color[u][1] = 0;
        sum[u] = 0, lazy[u] = 0;
        if (s == e) return;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
    }

    void modify(int s, int e, int ql, int qr, int u, int c)
    {
        if (ql <= s && e <= qr)
        {
            color[u][0] = c, color[u][1] = c;
            sum[u] = e - s, lazy[u] = c;
            return;
        }
        pushdown(s, e, u);
        int mid = (s + e) >> 1;
        if (ql <= mid) modify(s, mid, ql, qr, lson, c);
        if (qr > mid) modify(mid + 1, e, ql, qr, rson, c);
        color[u][0] = color[lson][0], color[u][1] = color[rson][1];
        sum[u] = sum[lson] + sum[rson];
        if (color[lson][1] == color[rson][0]) ++sum[u];
    }

    inline data query(int s, int e, int ql, int qr, int u)
    {
        if (ql <= s && e <= qr) return data(color[u][0], color[u][1], sum[u]);
        pushdown(s, e, u);
        int mid = (s + e) >> 1;
        if (ql <= mid && qr > mid)
        {
            data res_l = query(s, mid, ql, qr, lson);
            data res_r = query(mid + 1, e, ql, qr, rson);
            int res = res_l.sum + res_r.sum;
            if (res_l.rc == res_r.lc) ++res;
            return data(res_l.lc, res_r.rc, res);
        }
        if (ql <= mid) return query(s, mid, ql, qr, lson);
        return query(mid + 1, e, ql, qr, rson);
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

inline void update(int x, int y, int c)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]]) swap(x, y);
        tree.modify(1, n, dfn[top[x]], dfn[x], 1, c);
        x = par[top[x]];
    }
    if (depth[x] > depth[y]) swap(x, y);
    tree.modify(1, n, dfn[x], dfn[y], 1, c);
}

inline int query(int x, int y)
{
    int cur = 0;
    data ans[2], res;
    ans[0] = data(0, 0, 0), ans[1] = data(0, 0, 0);
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
        {
            swap(x, y);
            cur ^= 1;
        }
        res = tree.query(1, n, dfn[top[x]], dfn[x], 1);
        if (cur == 0)
        {
            ans[0].sum += res.sum;
            if (ans[0].rc == res.rc) ++ans[0].sum;
            ans[0].rc = res.lc;
        }
        else
        {
            ans[1].sum += res.sum;
            if (ans[1].lc == res.rc) ++ans[1].sum;
            ans[1].lc = res.lc;
        }
        x = par[top[x]];
    }
    if (depth[x] < depth[y])
    {
        swap(x, y);
        cur ^= 1;
    }
    res = tree.query(1, n, dfn[y], dfn[x], 1);
    if (cur == 0)
    {
        ans[0].sum += res.sum;
        if (ans[0].rc == res.rc) ++ans[0].sum;
        ans[0].rc = res.lc;
    }
    else
    {
        ans[1].sum += res.sum;
        if (ans[1].lc == res.rc) ++ans[1].sum;
        ans[1].lc = res.lc;
    }
    if (ans[0].rc == ans[1].lc) return ans[0].sum + ans[1].sum + 1;
    return ans[0].sum + ans[1].sum;
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
        for (int i = 1, u, v; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        dfs_son(1, 0), dfs_top(1, 1);
        tree.build(1, n, 1);
        for (int i = 1; i <= n; ++i)
            tree.modify(1, n, dfn[i], dfn[i], 1, -dfn[i]);
        int opt, a, b;
        while (m--)
        {
            scanf("%d%d%d", &opt, &a, &b);
            if (opt == 1) update(a, b, m + 1);
            else printf("%d\n", query(a, b));
        }
    }
    return 0;
}