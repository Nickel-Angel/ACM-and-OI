/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 1e5 + 10;

int n, m, s, head[maxn * 6], to[maxn * 6], next[maxn * 6], val[maxn * 6], tot;
int cnt, a[maxn * 6], dis[maxn * 6], in[maxn * 6];
std::queue<int> q;

inline void add_edge(int u, int v, int w)
{
    //printf("edge %d %d %d\n", u, v, w);
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
    ++in[v];
}

class Segtree
{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
  private:
    int id[maxn << 2], bound;

    void build(int s, int e, int u)
    {
        if (s == e)
        {
            id[u] = s;
            return;
        }
        id[u] = ++cnt;
        int mid = (s + e) >> 1;
        build(s, mid, lson), build(mid + 1, e, rson);
        add_edge(id[u], id[lson], 0), add_edge(id[u], id[rson], 0);
    }

    void link(int s, int e, int ql, int qr, int u, int p, int w)
    {
        if (ql <= s && e <= qr)
        {
            add_edge(p, id[u], w);
            return;
        }
        int mid = (s + e) >> 1;
        if (ql <= mid)
            link(s, mid, ql, qr, lson, p, w);
        if (qr > mid)
            link(mid + 1, e, ql, qr, rson, p, w);
    }

  public:
    inline void build(const int &n)
    {
        bound = n;
        build(1, n, 1);
    }

    inline void link(const int &u, const int &l, const int &r, const int &w)
    {
        link(1, bound, l, r, 1, u, w);
    }

    #undef lson
    #undef rson
}tree;

int main()
{
    scanf("%d%d%d", &n, &s, &m);
    cnt = n;
    for (int i = 1, p; i <= s; ++i)
    {
        scanf("%d", &p);
        scanf("%d", a + p);
        dis[p] = a[p];
    }
    tree.build(n);
    for (int i = 1, l, r, k, cur; i <= m; ++i)
    {
        scanf("%d%d%d", &l, &r, &k);
        cur = l, ++cnt;
        for (int j = 1, x; j <= k; ++j)
        {
            scanf("%d", &x);
            add_edge(x, cnt, 0);
            if (cur < x)
                tree.link(cnt, cur, x - 1, 1);
            cur = x + 1;
        }
        if (cur <= r)
            tree.link(cnt, cur, r, 1);
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (!a[i])
            dis[i] = 1e9;
        if (!in[i])
            q.push(i);
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            --in[v];
            if (a[v] > dis[u] - val[c])
            {
                puts("NIE");
                return 0;
            }
            dis[v] = std::min(dis[v], dis[u] - val[c]);
            if (dis[v] < 1)
            {
                puts("NIE");
                return 0;
            }
            if (in[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (in[i])
        {
            puts("NIE");
            return 0;
        }
    }
    puts("TAK");
    for (int i = 1; i <= n; ++i)
        printf("%d ", dis[i]);
}