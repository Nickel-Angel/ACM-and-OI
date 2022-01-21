/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using std::max;
using std::sort;
using std::map;

const int maxn = 3e5 + 10;
int n, k, a[maxn], d[maxn], id[maxn];
int pre[maxn], next[maxn];
map<int, int> c;

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int v[maxn << 2], bound;

    void build(int s, int e, int u)
    {
        v[u] = -1;
        if (s == e)
            return;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
    }

    void modify(int s, int e, int u, int pos, int k)
    {
        if (s == e)
        {
            v[u] = max(v[u], k);
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            modify(s, mid, lson, pos, k);
        else
            modify(mid + 1, e, rson, pos, k);
        v[u] = max(v[lson], v[rson]);
    }

    int query(int s, int e, int u, int ql, int qr)
    {
        if (ql <= s && e <= qr)
            return v[u];
        int res = -1, mid = (s + e) >> 1;
        if (ql <= mid)
            res = max(res, query(s, mid, lson, ql, qr));
        if (qr > mid)
            res = max(res, query(mid + 1, e, rson, ql, qr));
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

inline void del(int x)
{
    next[pre[x]] = next[x];
    pre[next[x]] = pre[x];
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        id[i] = i, pre[i] = i - 1, next[i] = i + 1;
    }
    tree.build(n);
    sort(id + 1, id + n + 1, [&](int x, int y){return a[x] < a[y];});
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (a[id[i]] != a[id[i - 1]])
        {
            while (j < i)
            {
                del(id[j]);
                ++j;
            }
        }
        d[id[i]] = tree.query(pre[id[i]] + 1, next[id[i]] - 1) + 1;
        tree.modify(id[i], d[id[i]]);
    }
    int x = 0;
    for (int i = 1; i <= n; ++i)
    {
        x = max(x, d[id[i]]);
        c[a[id[i]]] = x;
    }
    long long ans = d[1];
    for (int i = 1, b; i <= k; ++i)
    {
        scanf("%d", &b);
        auto it = c.upper_bound(b);
        ans += ((--it) -> second);
    }
    printf("%lld\n", ans);
    return 0;
}