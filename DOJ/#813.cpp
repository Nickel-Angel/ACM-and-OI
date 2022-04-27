/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int maxn = 1e5 + 10;
int n, m;
char s[maxn];

struct node
{
    int ansl, ansr;
    
    node() {}

    node(int ansl, int ansr) : ansl(ansl), ansr(ansr) {}

    node operator + (const node& rhs) const
    {
        return node(ansl + rhs.ansl - min(ansl, rhs.ansr), ansr + rhs.ansr - min(ansl, rhs.ansr));
    }
};

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int bound;
    node v[maxn << 2];

    void build(int l, int r, int u)
    {
        v[u].ansl = 0, v[u].ansr = 0;
        if (l == r)
        {
            if (s[l] == '(')
                v[u].ansl = 1;
            else
                v[u].ansr = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, lson), build(mid + 1, r, rson);
        v[u] = v[lson] + v[rson];
    }

    node query(int l, int r, int u, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return v[u];
        node res(0, 0);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            res = res + query(l, mid, lson, ql, qr);
        if (qr > mid)
            res = res + query(mid + 1, r, rson, ql, qr);
        return res;
    }

  public:
    inline void build(int n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline node query(int ql, int qr)
    {
        return query(1, bound, 1, ql, qr);
    }
}tree;

int main()
{
    scanf("%d%d%s", &n, &m, s + 1);
    int l, r;
    tree.build(n);
    node u;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        u = tree.query(l, r);
        printf("%d\n", r - l + 1 - u.ansl - u.ansr);
    }
    return 0;
}