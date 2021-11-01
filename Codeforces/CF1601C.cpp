/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <vector>

const int maxn = 1e6 + 10;
int n, m, a[maxn], b[maxn], p[maxn], pre[maxn], suf[maxn];
std::map<int, int> id;
std::vector<int> c;

class BIT
{
  private:
    int v[maxn << 1], tag[maxn << 1], tim = 0, bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    inline void build(int n)
    {
        bound = n, ++tim;
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
        {
            if (tag[i] < tim)
                v[i] = 0;
            tag[i] = tim;
            v[i] += x;
        }
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
        {
            if (tag[i] == tim)
                res += v[i];
        }
        return res;
    }
}tree;

void solve(int l, int r, int ql, int qr)
{
    if (ql > qr)
        return;
    int mid = (ql + qr) >> 1;
    pre[l - 1] = 0, suf[l - 1] = 0;
    for (int i = l; i <= r; ++i)
    {
        pre[i] = 0, suf[i] = 0;
        if (b[mid] < a[i])
            ++pre[i];
        if (b[mid] > a[i])
            ++suf[i];
    }
    for (int i = l + 1; i <= r; ++i)
        pre[i] += pre[i - 1];
    for (int i = r - 1; i >= l; --i)
        suf[i] += suf[i + 1];
    for (int i = l; i <= r; ++i)
    {
        if (p[mid] == 0 || pre[i - 1] + suf[i] < pre[p[mid] - 1] + suf[p[mid]])
            p[mid] = i;
    }
    solve(l, p[mid], ql, mid - 1), solve(p[mid], r, mid + 1, qr);
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    memset(p, 0, sizeof(p));
    id.clear(), c.clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        c.push_back(a[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", b + i);
        c.push_back(b[i]);
    }
    std::sort(b + 1, b + m + 1), std::sort(c.begin(), c.end());
    int cnt = std::unique(c.begin(), c.end()) - c.begin();
    tree.build(cnt);
    for (int i = 0; i < cnt; ++i)
        id[c[i]] = i + 1;
    solve(1, n + 1, 1, m);
    c.clear();
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (p[j] == i)
        {
            c.push_back(id[b[j]]);
            //printf("%d ", b[j]);
            ++j;
        }   
        c.push_back(id[a[i]]);
        //printf("%d ", a[i]);
    }
    while (p[j] == n + 1)
    {
        c.push_back(id[b[j]]);
        //printf("%d ", b[j]);
        ++j;
    }
    //puts("");
    long long ans = 0;
    for (unsigned i = 0; i < c.size(); ++i)
    {
        ans += i - tree.query(c[i]);
        tree.add(c[i], 1);
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}