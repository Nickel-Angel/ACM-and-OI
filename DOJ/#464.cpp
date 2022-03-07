/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;

class BIT
{
  private:
    int v[200010], tag[200010], tim, bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }
  public:
    inline void init(int n)
    {
        bound = n;
        ++tim;
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
        {
            if (tag[i] < tim)
            {
                tag[i] = tim;
                v[i] = 0;
            }
            v[i] += x;
        }
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
        {
            if (tag[i] < tim)
            {
                tag[i] = tim;
                v[i] = 0;
            }
            res += v[i];
        }
        return res;
    }

    inline int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
}tree;

int n, q, a[maxn], b[200010], c[2000010], L[maxn], R[maxn], H[maxn];
int id[200010], ans[maxn];

inline void solve()
{
    scanf("%d%d", &n, &q);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        c[++cnt] = a[i];
    }
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d%d", L + i, R + i, H + i);
        c[++cnt] = H[i], ans[i] = 0;
        b[2 * i - 1] = L[i] - 1, b[2 * i] = R[i];
        id[2 * i - 1] = 2 * i - 1, id[2 * i] = 2 * i;
    }
    std::sort(c + 1, c + cnt + 1);
    std::sort(id + 1, id + 2 * q + 1, [&](int x, int y){return b[x] < b[y];});
    cnt = std::unique(c + 1, c + cnt + 1) - c - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(c + 1, c + cnt + 1, a[i]) - c;
    for (int i = 1; i <= q; ++i)
        H[i] = std::lower_bound(c + 1, c + cnt + 1, H[i]) - c;
    tree.init(cnt);
    for (int i = 1, j = 1; i <= 2 * q; ++i)
    {
        while (j <= b[id[i]])
        {
            tree.add(a[j], 1);
            ++j;
        }
        if (id[i] & 1)
            ans[(id[i] + 1) / 2] -= tree.query(H[(id[i] + 1) / 2]);
        else
            ans[(id[i] + 1) / 2] += tree.query(H[(id[i] + 1) / 2]);
    }
    for (int i = 1; i <= q; ++i)
        printf("%d%c", ans[i], " \n"[i == q]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}