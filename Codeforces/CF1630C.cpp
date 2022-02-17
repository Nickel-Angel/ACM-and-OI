/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, a[maxn], fir[maxn], last[maxn], l[maxn], r[maxn], f[maxn], id[maxn];

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int bound, v[maxn << 2];

    inline void build(int s, int e, int u)
    {
        v[u] = 0;
        if (s == e)
            return;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
    }

    void modify(int s, int e, int u, int pos, int k)
    {
        if (s == e)
        {
            v[u] = std::max(v[u], k);
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            modify(s, mid, lson, pos, k);
        else
            modify(mid + 1, e, rson, pos, k);
        v[u] = std::max(v[lson], v[rson]);
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
    inline void build(int n)
    {
        bound = n;
        build(1, bound, 1);
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (!fir[a[i]])
            fir[a[i]] = i;
        last[a[i]] = std::max(last[a[i]], i);
    }
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!fir[i] || fir[i] >= last[i] - 1)
            continue;
        l[++m] = fir[i];
        r[m] = last[i];
        id[m] = m;
    }
    tree.build(n);
    std::sort(id + 1, id + m + 1, [&](int x, int y){return r[x] < r[y];});
    for (int i = 1; i <= m; ++i)
    {
        f[r[id[i]]] = tree.query(l[id[i]] + 1, r[id[i]] - 1) + 1;
        tree.modify(r[id[i]], f[r[id[i]]]); 
    }
    printf("%d\n", f[n]);
    return 0;
}