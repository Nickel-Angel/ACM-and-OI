/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 3e5 + 10;
int k, n;
ll a[maxn], d[maxn];

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int bound;
    ll v[maxn << 2], lazy[maxn << 2];
    
    void build(int l, int r, int u)
    {
        lazy[u] = 0;
        if (l == r)
        {
            v[u] = d[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        v[u] = v[lson] + v[rson];
    }

    void modify(int l, int r, int u, int ql, int qr, ll k)
    {
        v[u] += k * (min(r, qr) - max(l, ql) + 1);
        if (ql <= l && r <= qr)
        {
            lazy[u] += k;
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid)
            modify(l, mid, lson, ql, qr, k);
        if (qr > mid)
            modify(mid + 1, r, rson, ql, qr, k);
    }

    ll query(int l, int r, int u, int ql, int qr, ll ex)
    {
        if (ql <= l && r <= qr)
            return v[u] + ex * (min(r, qr) - max(l, ql) + 1);
        int mid = (l + r) >> 1;
        ll res = 0;
        if (ql <= mid)
            res += query(l, mid, lson, ql, qr, ex + lazy[u]);
        if (qr > mid)
            res += query(mid + 1, r, rson, ql, qr, ex + lazy[u]);
        return res;
    }

  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void modify(int ql, int qr, ll k)
    {
        modify(1, bound, 1, ql, qr, k);
    }

    inline ll query(int ql, int qr)
    {
        return query(1, bound, 1, ql, qr, 0);
    }
    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", a + i);
        d[i] = a[i] - a[i - 1];
    }
    tree.build(n);
    ll cur, ans = 0;
    for (int i = n, l, tot; i > 0; --i)
    {
        cur = tree.query(1, i);
        if (cur <= 0)
            continue;
        l = max(1, i - k + 1);
        tot = i - l + 1;
        tree.modify(l, l + k - 1, -(cur + tot - 1) / tot);
        ans += (cur + tot - 1) / tot;
    }
    printf("%lld\n", ans);
    return 0;
}