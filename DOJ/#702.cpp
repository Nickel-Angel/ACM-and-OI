/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <vector>

using std::vector;
using std::array;

const int maxn = 5e5 + 10;
int n, q, a[maxn], b[maxn], f[maxn], s[maxn], top, ans[maxn];
vector<array<int, 3>> opt[maxn];

class BIT
{
  private:
    int v[maxn], bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    inline void build(int n)
    {
        bound = n;
        memset(v, 0, sizeof(v));
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
            v[i] += x;
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            res += v[i];
        return res;
    }
}tree;

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = 1; i <= n; ++i)
    {
        while (top && (a[s[top]] == a[i] || b[i] >= b[s[top]]))
            --top;
        f[i] = s[top] + 1;
        s[++top] = i;       
    }
    for (int i = 1, l, r; i <= q; ++i)
    {
        scanf("%d%d", &l, &r);
        opt[l - 1].push_back({-1, f[l], i});
        opt[r].push_back({1, f[l], i});
    }
    tree.build(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        tree.add(f[i], 1);
        for (auto p : opt[i])
            ans[p[2]] += p[0] * tree.query(p[1]);
    }
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}