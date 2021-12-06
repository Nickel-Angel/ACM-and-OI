/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

const int maxn = 2e5 + 10;
const int p = 2e9 + 1;
int n;

class Segtree
{
    #define lson ch[u][0]
    #define rson ch[u][1]
private:
    int v[maxn * 100][2], ch[maxn * 100][2], lazy[maxn * 100], cnt, root;

    inline int newnode(int Min, int Max)
    {
        ++cnt;
        ch[cnt][0] = ch[cnt][1] = 0;
        v[cnt][0] = Min, v[cnt][1] = Max;
        lazy[cnt] = 0;
        return cnt;
    }

    inline void pushup(int u)
    {
        v[u][0] = min(v[lson][0], v[rson][0]);
        v[u][1] = max(v[lson][1], v[rson][1]);
    }

    inline void pushdown(int s, int e, int u)
    {
        if (!lazy[u])
            return;
        int mid = ((long long)s + e) >> 1;
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        v[lson][0] += lazy[u], v[lson][1] += lazy[u];
        v[rson][0] += lazy[u], v[rson][1] += lazy[u];
        lazy[lson] += lazy[u], lazy[rson] += lazy[u];
        lazy[u] = 0;
    }

    void modify(int s, int e, int &u, int ql, int qr, int k)
    {
        if (s > e)
            return;
        if (!u)
            u = newnode(s, e);
        if (ql <= s && e <= qr)
        {
            v[u][0] += k, v[u][1] += k;
            lazy[u] += k;
            return;
        }
        int mid = ((long long)s + e) >> 1;
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        pushdown(s, e, u);
        if (ql <= mid)
            modify(s, mid, lson, ql, qr, k);
        if (qr > mid)
            modify(mid + 1, e, rson, ql, qr, k);
        pushup(u);
    }

    int lower(int s, int e, int u, int x)
    {
        if ((s == e) || v[u][0] == v[u][1] && v[u][0] < x)
            return e;
        int mid = ((long long)s + e) >> 1;
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        pushdown(s, e, u);
        return v[rson][0] < x ? lower(mid + 1, e, rson, x) : lower(s, mid, lson, x);
    }

    int upper(int s, int e, int u, int x)
    {
        //printf("%d %d %d\n", s, e, v[u][1]);
        if (v[u][0] == v[u][1] && v[u][1] > x)
            return s;
        int mid = ((long long)s + e) >> 1;
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        pushdown(s, e, u);
        return v[lson][1] > x ? upper(s, mid, lson, x) : upper(mid + 1, e, rson, x); 
    }

    int query(int s, int e, int u, int pos)
    {
        if (s == e)
            return v[u][0];
        int mid = ((long long)s + e) >> 1;
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        pushdown(s, e, u);
        return pos <= mid ? query(s, mid, lson, pos) : query(mid + 1, e, rson, pos);
    }

    int query_min(int s, int e, int u, int ql, int qr)
    {
        if (ql <= s && e <= qr)
            return v[u][0];
        int mid = ((long long)s + e) >> 1, res = 2e9;
        pushdown(s, e, u);
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        if (ql <= mid)
            res = min(res, query_min(s, mid, lson, ql, qr));
        if (qr > mid)
            res = min(res, query_min(mid + 1, e, rson, ql, qr));
        return res;
    }

    int query_max(int s, int e, int u, int ql, int qr)
    {
        if (ql <= s && e <= qr)
            return v[u][1];
        int mid = ((long long)s + e) >> 1, res = -2e9;
        pushdown(s, e, u);
        if (!lson)
            lson = newnode(s, mid);
        if (!rson)
            rson = newnode(mid + 1, e);
        if (ql <= mid)
            res = max(res, query_max(s, mid, lson, ql, qr));
        if (qr > mid)
            res = max(res, query_max(mid + 1, e, rson, ql, qr));
        return res;
    }
public:
    Segtree()
    {
        cnt = 0;
        root = newnode(0, p - 1);
    }

    inline void modify(int ql, int qr, int k)
    {
        modify(0, p - 1, root, ql, qr, k);
    }

    inline int lower(int x)
    {
        return lower(0, p - 1, root, x);
    }

    inline int upper(int x)
    {
        return upper(0, p - 1, root, x);
    }

    inline int query(int pos)
    {
        return query(0, p - 1, root, pos);
    }

    inline int query_min(int ql, int qr)
    {
        return query_min(0, p - 1, root, ql, qr);
    }

    inline int query_max(int ql, int qr)
    {
        return query_max(0, p - 1, root, ql, qr);
    }

    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d", &n);
    int l, r, t, k, x, ans = 0;
    while (n--)
    {
        scanf("%d", &t);
        l = tree.lower(t);
        //puts("lower");
        r = tree.upper(t);
        //puts("upper");
        if (tree.query_min(0, p - 1) < t)
            tree.modify(0, l, 1);
        if (tree.query_max(0, p - 1) > t)
            tree.modify(r, p - 1, -1);
        scanf("%d", &k);
        for (int i = 0; i < k; ++i)
        {
            scanf("%d", &x);
            x = (x + ans) % (int)(1e9 + 1);
            ans = tree.query(x);
            printf("%d\n", ans);
        }
    }
    return 0;
}