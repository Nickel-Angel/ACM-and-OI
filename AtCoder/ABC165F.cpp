/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

const int maxn = 2e5 + 10;

int n, a[maxn], head[maxn], to[maxn << 1], next[maxn << 1], tot = 0;
int b[maxn], ans[maxn], cnt;
std::map<int, int> id;

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
private:
    int v[maxn << 2], bound;

    inline void pushup(int u)
    {
        v[u] = std::max(v[lson], v[rson]);
    }

    void build(int s, int e, int u)
    {
        v[u] = 0;
        if (s == e)
            return;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
    }

    void assign(int s, int e, int u, int pos, int k)
    {
        if (s == e)
        {
            v[u] = k;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            assign(s, mid, lson, pos, k);
        else
            assign(mid + 1, e, rson, pos, k);
        pushup(u);
    }

    int query(int s, int e, int u, int ql, int qr)
    {
        if (ql <= s && e <= qr)
            return v[u];
        int res = 0, mid = (s + e) >> 1;
        if (ql <= mid)
            res = std::max(res, query(s, mid, lson, ql, qr));
        if (qr > mid)
            res = std::max(res, query(mid + 1, e, rson, ql, qr));
        return res; 
    }
public:
    inline void build(const int &n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void assign(const int &pos, const int &k)
    {
        assign(1, bound, 1, pos, k);
    }

    inline int query(const int &ql, const int &qr)
    {
        return query(1, bound, 1, ql, qr);
    }
}tree;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    int cur, bef;
    if (a[u] > 1)
    {
        cur = tree.query(1, a[u] - 1) + 1;
        bef = tree.query(a[u], a[u]);
        tree.assign(a[u], cur);
    }
    else
    {
        bef = tree.query(1, 1), cur = 1;
        tree.assign(1, 1);
    }
    ans[u] = tree.query(1, cnt);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
    }
    tree.assign(a[u], bef);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    cnt = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    tree.build(cnt);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}