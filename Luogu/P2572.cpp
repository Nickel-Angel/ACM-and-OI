/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;
using std::swap;

const int maxn = 1e5 + 10;
int n, m, a[maxn];

struct node
{
    int l, r, lmax, rmax, v;

    node() {}

    node(int l, int r, int lmax, int rmax, int v) : l(l), r(r), lmax(lmax), rmax(rmax), v(v) {}

    node operator + (const node& rhs) const
    {
        node res;
        res.l = l, res.r = rhs.r;
        res.lmax = lmax == rhs.l - l ? lmax + rhs.lmax : lmax;
        res.rmax = rhs.rmax == rhs.r - r ? rmax + rhs.rmax : rhs.rmax;
        res.v = max({v, rhs.v, rmax + rhs.lmax});
        return res;
    }
};

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int lmax[maxn << 2][2], rmax[maxn << 2][2], v[maxn << 2][2], cnt[maxn << 2][2];
    int cover[maxn << 2], bound;
    bool flip[maxn << 2];

    inline void pushup(int l, int r, int u)
    {
        int mid = (l + r) >> 1;
        lmax[u][0] = lmax[lson][0] == mid - l + 1 ? lmax[lson][0] + lmax[rson][0] : lmax[lson][0];
        rmax[u][0] = rmax[rson][0] == r - mid ? rmax[rson][0] + rmax[lson][0] : rmax[rson][0];
        lmax[u][1] = lmax[lson][1] == mid - l + 1 ? lmax[lson][1] + lmax[rson][1] : lmax[lson][1];
        rmax[u][1] = rmax[rson][1] == r - mid ? rmax[rson][1] + rmax[lson][1] : rmax[rson][1];
        v[u][0] = max({v[lson][0], v[rson][0], rmax[lson][0] + lmax[rson][0]});
        v[u][1] = max({v[lson][1], v[rson][1], rmax[lson][1] + lmax[rson][1]});
        cnt[u][0] = cnt[lson][0] + cnt[rson][0];
        cnt[u][1] = cnt[lson][1] + cnt[rson][1];
    }

    inline void pushdown(int l, int r, int u)
    {
        if (~cover[u])
        {
            int mid = (l + r) >> 1;
            lmax[lson][cover[u]] = mid - l + 1, rmax[lson][cover[u]] = mid - l + 1;
            lmax[lson][cover[u] ^ 1] = 0, rmax[lson][cover[u] ^ 1] = 0;
            v[lson][cover[u]] = mid - l + 1, v[lson][cover[u] ^ 1] = 0;
            cnt[lson][cover[u]] = mid - l + 1, cnt[lson][cover[u] ^ 1] = 0;
            
            lmax[rson][cover[u]] = r - mid, rmax[rson][cover[u]] = r - mid;
            lmax[rson][cover[u] ^ 1] = 0, rmax[rson][cover[u] ^ 1] = 0;
            v[rson][cover[u]] = r - mid, v[rson][cover[u] ^ 1] = 0;
            cnt[rson][cover[u]] = r - mid, cnt[rson][cover[u] ^ 1] = 0;
            
            cover[lson] = cover[u], cover[rson] = cover[u];
            flip[lson] = false, flip[rson] = false;
            cover[u] = -1;
        }
        if (flip[u])
        {
            swap(lmax[lson][0], lmax[lson][1]), swap(rmax[lson][0], rmax[lson][1]);
            swap(v[lson][0], v[lson][1]), swap(cnt[lson][0], cnt[lson][1]);
            swap(lmax[rson][0], lmax[rson][1]), swap(rmax[rson][0], rmax[rson][1]);
            swap(v[rson][0], v[rson][1]), swap(cnt[rson][0], cnt[rson][1]);
            if (~cover[lson])
                cover[lson] ^= 1;
            else
                flip[lson] ^= true;
            if (~cover[rson])
                cover[rson] ^= 1;
            else
                flip[rson] ^= true;
            flip[u] = false;
        }
    }

    void build(int l, int r, int u)
    {
        cover[u] = -1, flip[u] = false;
        if (l == r)
        {
            lmax[u][a[l]] = 1, rmax[u][a[l]] = 1;
            lmax[u][a[l] ^ 1] = 0, rmax[u][a[l] ^ 1] = 0;
            v[u][a[l]] = 1, v[u][a[l] ^ 1] = 0;
            cnt[u][a[l]] = 1, cnt[u][a[l] ^ 1] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        pushup(l, r, u);
    }

    void assign(int l, int r, int u, int ql, int qr, int k)
    {
        if (ql <= l && r <= qr)
        {
            lmax[u][k] = r - l + 1, rmax[u][k] = r - l + 1;
            lmax[u][k ^ 1] = 0, rmax[u][k ^ 1] = 0;
            v[u][k] = r - l + 1, v[u][k ^ 1] = 0;
            cnt[u][k] = r - l + 1, cnt[u][k ^ 1] = 0;
            cover[u] = k, flip[u] = false;
            return;
        }
        pushdown(l, r, u);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            assign(l, mid, lson, ql, qr, k);
        if (qr > mid)
            assign(mid + 1, r, rson, ql, qr, k);
        pushup(l, r, u);
    }

    void reverse(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            swap(lmax[u][0], lmax[u][1]), swap(rmax[u][0], rmax[u][1]);
            swap(v[u][0], v[u][1]), swap(cnt[u][0], cnt[u][1]);
            if (~cover[u])
                cover[u] ^= 1;
            else
                flip[u] ^= true;
            return;
        }
        pushdown(l, r, u);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            reverse(l, mid, lson, ql, qr);
        if (qr > mid)
            reverse(mid + 1, r, rson, ql, qr);
        pushup(l, r, u);
    }

    int query_cnt(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return cnt[u][1];
        pushdown(l, r, u);
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid)
            res += query_cnt(l, mid, lson, ql, qr);
        if (qr > mid)
            res += query_cnt(mid + 1, r, rson, ql, qr);
        return res;
    }

    node query_max(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return node(l, r, lmax[u][1], rmax[u][1], v[u][1]);
        pushdown(l, r, u);
        int mid = (l + r) >> 1;
        if (ql <= mid && qr > mid)
            return query_max(l, mid, lson, ql, qr) + query_max(mid + 1, r, rson, ql, qr);
        if (ql <= mid)
            return query_max(l, mid, lson, ql, qr);
        return query_max(mid + 1, r, rson, ql, qr);
    }
  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void assign(int ql, int qr, int k)
    {
        assign(1, bound, 1, ql, qr, k);
    }

    inline void reverse(int ql, int qr)
    {
        reverse(1, bound, 1, ql, qr);
    }

    inline int query_cnt(int ql, int qr)
    {
        return query_cnt(1, bound, 1, ql, qr);
    }

    inline int query_max(int ql, int qr)
    {
        return query_max(1, bound, 1, ql, qr).v;
    }
    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    tree.build(n);
    int opt, l, r;
    while (m--)
    {
        scanf("%d%d%d", &opt, &l, &r);
        ++l, ++r;
        if (opt <= 1)
            tree.assign(l, r, opt);
        else if (opt == 2)
            tree.reverse(l, r);
        else if (opt == 3)
            printf("%d\n", tree.query_cnt(l, r));
        else
            printf("%d\n", tree.query_max(l, r));
    }
    return 0;
}