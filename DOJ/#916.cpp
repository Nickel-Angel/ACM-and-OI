/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], p[maxn], f[maxn];

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
            v[i] = std::max(v[i], x);
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i))
            res = std::max(res, v[i]);
        return res;
    }
}tree;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        p[b[i]] = i;
    }
    tree.build(n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = std::max(1, a[i] - 4); j <= std::min(n, a[i] + 4); ++j)
            f[p[j]] = std::max(f[p[j]], tree.query(p[j] - 1) + 1);
        for (int j = std::max(1, a[i] - 4); j <= std::min(n, a[i] + 4); ++j)
            tree.add(p[j], f[p[j]]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = std::max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}