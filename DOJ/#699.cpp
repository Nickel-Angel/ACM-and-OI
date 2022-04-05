/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, a[maxn];

class BIT
{
  private:
    int v[maxn], bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    inline void init(int n)
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
        for (int i = pos; i > 0; i -= lowbit(i))
            res = std::max(res, v[i]);
        return res;
    }
}tree;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    tree.init(n);
    int ans = 0;
    for (int i = n, cur; i > 0; --i)
    {
        cur = tree.query(a[i]) + 1;
        ans = std::max(ans, cur);
        tree.add(a[i], cur);
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