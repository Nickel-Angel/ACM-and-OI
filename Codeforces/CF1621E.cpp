/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, m, a[maxn], k[maxn];
int avg[maxn], suf[maxn];
ll sum[maxn];
vector<int> b[maxn];

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
private:
    int v[maxn << 2], lazy[maxn << 2], bound;

    inline void pushdown(int u)
    {
        if (!lazy[u])
            return;
        lazy[lson] += lazy[u], lazy[rson] += lazy[u];
        v[lson] += lazy[u], v[rson] += lazy[u];
        lazy[u] = 0;
    }

    void modify(int s, int e, int u, int ql, int qr, int k)
    {
        if (ql <= s && e <= qr)
        {
            v[u] += k, lazy[u] += k;
            return;
        }
        pushdown(u);
        int mid = (s + e) >> 1;
        if (ql <= mid)
            modify(s, mid, lson, ql, qr, k);
        if (qr > mid)
            modify(mid + 1, e, rson, ql, qr, k);
        v[u] = min(v[lson], v[rson]);
    }

    int query(int s, int e, int u, int ql, int qr)
    {
        if (ql <= s && e <= qr)
            return v[u];
        pushdown(u);
        int mid = (s + e) >> 1, res = 1e9;
        if (ql <= mid)
            res = min(res, query(s, mid, lson, ql, qr));
        if (qr > mid)
            res = min(res, query(mid + 1, e, rson, ql, qr));
        return res;
    }

    void build(int s, int e, int u)
    {
        lazy[u] = 0;
        if (s == e)
        {
            v[u] = suf[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
        v[u] = min(v[lson], v[rson]);
    }
public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void modify(int ql, int qr, int k)
    {
        modify(1, bound, 1, ql, qr, k);
    }

    inline int query(int ql, int qr)
    {
        return query(1, bound, 1, ql, qr);
    }
    #undef lson
    #undef rson
}tree;

inline void solve()
{
    scanf("%d%d", &n, &m);
    memset(suf, 0, sizeof(suf));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++suf[a[i]];
    }
    for (int i = 1, x; i <= m; ++i)
    {
        sum[i] = 0, b[i].clear();
        scanf("%d", k + i);
        for (int j = 0; j < k[i]; ++j)
        {
            scanf("%d", &x);
            b[i].push_back(x);
            sum[i] += x;
        }
        avg[i] = (sum[i] + k[i] - 1) / k[i];
        --suf[avg[i]];
    }
    for (int i = (int)1e5 - 1; i > 0; --i)
        suf[i] += suf[i + 1];
    tree.build(1e5);
    for (int i = 1, cur; i <= m; ++i)
    {
        tree.modify(1, avg[i], 1);
        for (int j = 0; j < k[i]; ++j)
        {
            cur = (sum[i] - b[i][j] + k[i] - 2) / (k[i] - 1);
            tree.modify(1, cur, -1);
            printf("%d", tree.query(1, 1e5) >= 0);
            tree.modify(1, cur, 1);
        }
        tree.modify(1, avg[i], -1);
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}