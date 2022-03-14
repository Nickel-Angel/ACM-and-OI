/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, K, m, Q, a[maxn], b[maxn], q[maxn], id[maxn][2];
int f[maxn][21][2];

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int v[maxn << 2][2], bound;

    void build(int l, int r, int u)
    {
        v[u][0] = n, v[u][1] = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
    }

    void assign(int l, int r, int u, int pos, int left, int right)
    {
        if (l == r)
        {
            v[u][0] = left;
            v[u][1] = right;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            assign(l, mid, lson, pos, left, right);
        else
            assign(mid + 1, r, rson, pos, left, right);
        v[u][0] = std::min(v[lson][0], v[rson][0]);
        v[u][1] = std::max(v[lson][1], v[rson][1]);
    }

    int query_left(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return v[u][0];
        int mid = (l + r) >> 1, res = n;
        if (ql <= mid)
            res = std::min(res, query_left(l, mid, lson, ql, qr));
        if (qr > mid)
            res = std::min(res, query_left(mid + 1, r, rson, ql, qr));
        return res;
    }

    int query_right(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return v[u][1];
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid)
            res = std::max(res, query_right(l, mid, lson, ql, qr));
        if (qr > mid)
            res = std::max(res, query_right(mid + 1, r, rson, ql, qr));
        return res;
    }
  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void assign(int pos, int left, int right)
    {
        assign(1, bound, 1, pos, left, right);
    }

    inline int query_left(int ql, int qr)
    {
        return query_left(1, bound, 1, ql, qr);
    }

    inline int query_right(int ql, int qr)
    {
        return query_right(1, bound, 1, ql, qr);
    }
    #undef lson
    #undef rson
}tree[20];

inline int query(int s, int t)
{
    int l = s, r = s, curl, curr, res = 0;
    for (int i = 19; i >= 0; --i)
    {
        curl = tree[i].query_left(l, r);
        curr = tree[i].query_right(l, r);
        if (curl <= t && t <= curr)
            continue;
        l = curl, r = curr; 
        res += (1 << i);
    }
    curl = tree[0].query_left(l, r), curr = tree[0].query_right(l, r);
    if (curl <= t && t <= curr)
        return res + 1;
    return -1;
}

int main()
{
    scanf("%d%d%d", &n, &K, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", a + i, b + i);
        if (a[i] > b[i])
        {
            if (!id[a[i]][0] || b[id[a[i]][0]] > b[i])
                id[a[i]][0] = i;
        }
        else
        {
            if (!id[a[i]][1] || b[id[a[i]][1]] < b[i])
                id[a[i]][1] = i;
        }
    }
    int L = 1, R = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (L <= R && i > std::min(a[q[L]] + K, b[q[L]]) - 1)
            ++L;
        if (id[i][1])
        {
            while (L <= R && b[id[i][1]] > b[q[R]])
                --R;
            q[++R] = id[i][1];
        }
        f[i][0][1] = L > R ? i : b[q[L]];
    }
    L = 1, R = 0;
    for (int i = n; i > 0; --i)
    {
        while (L <= R && i < std::max(a[q[L]] - K, b[q[L]]) + 1)
            ++L;
        if (id[i][0])
        {
            while (L <= R && b[id[i][0]] < b[q[R]])
                --R;
            q[++R] = id[i][0];
        }
        f[i][0][0] = L > R ? i : b[q[L]];
    }
    tree[0].build(n);
    for (int i = 1; i <= n; ++i)
        tree[0].assign(i, f[i][0][0], f[i][0][1]);
    for (int j = 1; j < 20; ++j)
    {
        tree[j].build(n);
        for (int i = 1; i <= n; ++i)
        {
            f[i][j][0] = std::min(i, tree[j - 1].query_left(f[i][j - 1][0], f[i][j - 1][1]));
            f[i][j][1] = std::max(i, tree[j - 1].query_right(f[i][j - 1][0], f[i][j - 1][1]));
            tree[j].assign(i, f[i][j][0], f[i][j][1]);
        }
    }
    scanf("%d", &Q);
    int s, t;
    while (Q--)
    {
        scanf("%d%d", &s, &t);
        printf("%d\n", query(s, t));
    }
    return 0;
}