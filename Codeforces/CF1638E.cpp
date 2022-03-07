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

const int maxn = 1e6 + 10;
int n, q;

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    ll lazy[maxn], v[maxn << 2];
    int color[maxn << 2], bound;

    inline void pushdown(int u)
    {
        if (v[u])
        {
            v[lson] += v[u];
            v[rson] += v[u];
            v[u] = 0;
        }
        if (color[u])
        {
            color[lson] = color[u];
            color[rson] = color[u];
        }
    }

    void build(int l, int r, int u)
    {
        v[u] = 0, color[u] = 1;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
    }

    void modify(int l, int r, int u, int ql, int qr, int c)
    {
        if (color[u] && ql <= l && r <= qr)
        {
            v[u] += lazy[color[u]] - lazy[c];
            color[u] = c;
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            modify(l, mid, lson, ql, qr, c);
        if (qr > mid)
            modify(mid + 1, r, rson, ql, qr, c);
        if (color[lson] && color[rson] && color[lson] == color[rson])
            color[u] = color[lson];
        else
            color[u] = 0;
    }

    ll query(int l, int r, int u, int pos)
    {
        if (l == r)
            return v[u] + lazy[color[u]];
        pushdown(u);
        int mid = (l + r) >> 1;
        if (pos <= mid)
            return query(l, mid, lson, pos);
        return query(mid + 1, r, rson, pos);
    }
    
  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void add(int c, int x)
    {
        lazy[c] += x;
    }

    inline void modify(int ql, int qr, int c)
    {
        modify(1, bound, 1, ql, qr, c);
    }

    inline ll query(int pos)
    {
        return query(1, bound, 1, pos);
    }
    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d%d", &n, &q);
    tree.build(n);
    char opt[10];
    int l, r, c, x;
    while (q--)
    {
        scanf("%s", opt);
        if (opt[0] == 'C')
        {
            scanf("%d%d%d", &l, &r, &c);
            tree.modify(l, r, c);
        }
        else if (opt[0] == 'A')
        {
            scanf("%d%d", &c, &x);
            tree.add(c, x);
        }
        else
        {
            scanf("%d", &x);
            printf("%lld\n", tree.query(x));
        }
    }
    return 0;
}