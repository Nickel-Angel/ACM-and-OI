/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

const int maxn = 5e5 + 10;
int n, m, pre[maxn], next[maxn], a[maxn], d[maxn];
int ans[maxn], l[maxn], r[maxn], id[maxn];
std::map<int, int> cur;

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int v[maxn << 2], bound;

    void build(int l, int r, int u)
    {
        if (l == r)
        {
            v[u] = d[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson); 
        v[u] = std::min(v[lson], v[rson]);
    }

    void modify(int l, int r, int u, int pos, int k)
    {
        if (l == r)
        {
            v[u] = k;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            modify(l, mid, lson, pos, k);
        else
            modify(mid + 1, r, rson, pos, k);
        v[u] = std::min(v[lson], v[rson]);
    }

    int query(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return v[u];
        int mid = (l + r) >> 1, res = n + 1;
        if (ql <= mid)
            res = std::min(res, query(l, mid, lson, ql, qr));
        if (qr > mid)
            res = std::min(res, query(mid + 1, r, rson, ql, qr));
        return res;
    }
  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void modify(int pos, int k)
    {
        modify(1, bound, 1, pos, k);
    }

    inline int query(int ql, int qr)
    {
        return query(1, bound, 1, ql, qr);
    }

    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (cur.count(a[i]))
        {
            pre[i] = cur[a[i]];
            next[pre[i]] = i;
            d[i] = i - pre[i];
        }
        else
            d[i] = n + 1;
        cur[a[i]] = i;
    }
    tree.build(n);
    for (int i = 1; i <= m; ++i)
    {
        id[i] = i;
        scanf("%d%d", l + i, r + i);
    }
    std::sort(id + 1, id + m + 1, [&](int x, int y){return l[x] < l[y];});
    int j = 1;
    for (int i = 1; i <= m; ++i)
    {
        while (j < l[id[i]])
        {
            if (next[j])
                tree.modify(next[j], n + 1);
            ++j;
        }
        ans[id[i]] = tree.query(l[id[i]], r[id[i]]);
        if (ans[id[i]] == n + 1)
            ans[id[i]] = -1;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}