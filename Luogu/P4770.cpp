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

const int maxn = 5e5 + 10;
const int maxm = 1e6 + 10;
char s[maxn], t[maxm];
int n, m, root[maxn << 1], r[maxm], c[maxn], rank[maxn << 1];

class Segtree
{
  private:
    int ch[maxn * 40][2], tot = 0;

    void insert(int l, int r, int &u, int pos)
    {
        if (!u)
            u = ++tot;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (pos <= mid)
            insert(l, mid, ch[u][0], pos);
        else
            insert(mid + 1, r, ch[u][1], pos);
    }

    bool query(int l, int r, int u, int ql, int qr)
    {
        if (!u)
            return false;
        if (ql <= l && r <= qr)
            return true;
        int mid = (l + r) / 2;
        bool res = false;
        if (ql <= mid)
            res |= query(l, mid, ch[u][0], ql, qr);
        if (qr > mid)
            res |= query(mid + 1, r, ch[u][1], ql, qr);
        return res;
    }

  public:
    inline void insert(int &u, int pos)
    {
        insert(1, n, u, pos);
    }

    int merge(int x, int y)
    {
        if (!x || !y)
            return x | y;
        int u = ++tot;
        ch[u][0] = merge(ch[x][0], ch[y][0]);
        ch[u][1] = merge(ch[x][1], ch[y][1]);
        return u;
    }

    inline bool query(int u, int ql, int qr)
    {
        return query(1, n, u, ql, qr);
    }
}tree;

template<int N>
class SAM
{
  private:
    int next[N << 1][26], len[N << 1], link[N << 1], fir[N << 1];
    int tot, last;

  public:
    SAM()
    {
        tot = 1, last = 1;
        len[1] = 0, link[1] = 0;
    }

    inline void clear()
    {
        tot = 1, last = 1;
        len[1] = 0, link[1] = 0;
        memset(next[1], 0, sizeof(next[1]));
    }

    inline void extend(int x, int pos)
    {
        int cur = ++tot, p = last;
        len[cur] = len[p] + 1, fir[cur] = len[p] + 1;
        if (pos)
            tree.insert(root[cur], pos);
        memset(next[p], 0, sizeof(next[p]));
        while (p && !next[p][x])
        {
            next[p][x] = cur;
            p = link[p];
        }
        if (!p)
            link[cur] = 1;
        else
        {
            int q = next[p][x];
            if (len[p] + 1 == len[q])
                link[cur] = q;
            else
            {
                int clone = ++tot;
                len[clone] = len[p] + 1, link[clone] = link[q];
                fir[clone] = fir[q];
                memcpy(next[clone], next[q], sizeof(next[q]));
                while (p && next[p][x] == q)
                {
                    next[p][x] = clone;
                    p = link[p];
                }
                link[cur] = link[q] = clone;
            }
        }
        last = cur;
    }

    void segtree_init()
    {
        for (int i = 1; i <= tot; ++i)
            ++c[len[i]];
        for (int i = 1; i <= n; ++i)
            c[i] += c[i - 1];
        for (int i = 1; i <= tot; ++i)
            rank[--c[len[i]]] = i;
        for (int i = tot; i > 0; --i)
            root[link[rank[i]]] = tree.merge(root[link[rank[i]]], root[rank[i]]);
    }

    inline void find(char *s, int L, int R)
    {
        int p = 1, x;
        for (int i = 1; i <= m; ++i)
        {
            x = s[i] - 'a', r[i] = r[i - 1];
            while (true)
            {
                if (next[p][x] && tree.query(root[next[p][x]], L + r[i], R))
                {
                    ++r[i];
                    p = next[p][x];
                    break;
                }
                if (!r[i])
                    break;
                --r[i];
                if (r[i] == len[link[p]])
                    p = link[p];
            }
        }
    }

    ll calc()
    {
        ll res = 0;
        for (int i = 2; i <= tot; ++i)
            res += max(0, len[i] - max(len[link[i]], r[fir[i]]));
        return res;
    }
};

SAM<maxn> S;
SAM<maxm> T;

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        S.extend(s[i] - 'a', i);
    S.segtree_init();
    int q, l, r;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s%d%d", t + 1, &l, &r);
        m = strlen(t + 1);
        S.find(t, l, r);
        T.clear();
        for (int i = 1; i <= m; ++i)
            T.extend(t[i] - 'a', 0);
        printf("%lld\n", T.calc());
    }
    return 0;
}