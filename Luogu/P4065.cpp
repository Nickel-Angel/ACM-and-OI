/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 3e5 + 10;

struct data
{
    int color, pos;
    
    data() {}
    
    data(int _color, int _pos)
    {
        color = _color, pos = _pos;
    }
};

int T, n, a[maxn], start[maxn], end[maxn], top;
data s[maxn];

class Segtree
{
    #define lson u << 1
    #define rson u << 1 | 1
  private:
    int sum[maxn];
    bool lazy[maxn];

    inline void pushdown(int s, int e, int u)
    {
        if (!lazy[u]) return;
        lazy[lson] = true, lazy[rson] = true;
        sum[lson] = 0, sum[rson] = 0;
        lazy[u] = false;
    }

  public:
    void build(int s, int e, int u)
    {
        lazy[u] = false;
        if (s == e)
        {
            sum[u] = 1;
            return;
        }
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
        sum[u] = sum[lson] + sum[rson];
    }

    void assign(int s, int e, int ql, int qr, int u)
    {
        if (ql <= s && e <= qr)
        {
            lazy[u] = true, sum[u] = 0;
            return;
        }
        pushdown(s, e, u);
        int mid = (s + e) >> 1;
        if (ql <= mid) assign(s, mid, ql, qr, lson);
        if (qr > mid) assign(mid + 1, e, ql, qr, rson);
        sum[u] = sum[lson] + sum[rson];
    }

    int query(int s, int e, int ql, int qr, int u)
    {
        if (ql <= s && e <= qr) return sum[u];
        pushdown(s, e, u);
        int mid = (s + e) >> 1, res = 0;
        if (ql <= mid) res += query(s, mid, ql, qr, lson);
        if (qr > mid) res += query(mid + 1, e, ql, qr, rson);
        return res;
    }
    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d", &T);
    s[0] = data(0, 0);
    long long ans = 0;
    while (T--)
    {
        top = 0, ans = 0;
        std::memset(start, 0, sizeof(start));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            if (!start[a[i]]) start[a[i]] = i;
            end[a[i]] = i;
        }
        tree.build(1, n, 1);
        for (int r = 1; r <= n; ++r)
        {
            if (end[a[r]] == r && start[a[r]] != end[a[r]]) 
                tree.assign(1, n, start[a[r]] + 1, end[a[r]], 1);
            else
                s[++top] = data(a[r], r);
            while (top && end[s[top].color] <= r) 
                --top;
            int l = s[top].pos;
            if (l != r) 
                ans += tree.query(1, n, l + 1, r, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}