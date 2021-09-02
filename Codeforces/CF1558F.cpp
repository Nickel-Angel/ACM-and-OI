/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int n, a[maxn], id[maxn];
bool vis[maxn];

class Segtree
{
    #define lson u << 1
    #define rson u << 1 | 1
  private:
    int val[maxn << 2], lazy[maxn << 2];

    inline void pushdown(int u)
    {
        if (!lazy[u])
            return;
        val[lson] += lazy[u], val[rson] += lazy[u];
        lazy[lson] += lazy[u], lazy[rson] += lazy[u];
        lazy[u] = 0;
    }

  public:
    void build(int s, int e, int u)
    {
        val[u] = -inf, lazy[u] = 0;
        if (s == e)
        {
            val[u] += s - 2;
            return;
        }
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
    }

    void modify(int s, int e, int ql, int qr, int u, int x)
    {
        if (ql <= s && e <= qr)
        {
            val[u] += x;
            lazy[u] += x;
            return;
        }
        pushdown(u);
        int mid = (s + e) >> 1;
        if (ql <= mid)
            modify(s, mid, ql, qr, lson, x);
        if (qr > mid)
            modify(mid + 1, e, ql, qr, rson, x);
        val[u] = max(val[lson], val[rson]);
    }

    int query(int s, int e, int ql, int qr, int u)
    {
        if (ql <= s && e <= qr)
            return val[u];
        pushdown(u);
        int res = -inf, mid = (s + e) >> 1;
        if (ql <= mid)
            res = max(res, query(s, mid, ql, qr, lson));
        if (qr > mid)
            res = max(res, query(mid + 1, e, ql, qr, rson));
        return res;
    }
}tree;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        id[a[i]] = i, vis[i] = false;
    }
    tree.build(1, n, 1);
    int t = 0, ans = 0;
    for (int i = 1; i < n; ++i)
    {
        vis[id[i]] = true;
        while (vis[t + 1])
            ++t;
        if (id[i] != n)
            tree.modify(1, n, id[i] + 1, n, 1, -2);
        tree.modify(1, n, id[i], id[i], 1, inf + (id[i] & 1));
        ans = max(ans, tree.query(1, n, t + 1, n, 1) + i);
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}