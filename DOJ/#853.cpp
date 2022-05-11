/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, m, a, b, x[maxn], y[maxn], id[maxn], help[maxn];

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
        memset(v, 0, sizeof(v));
        bound = n;
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
            v[i] += x;
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i))
            res += v[i];
        return res;
    }
}tree;

int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= a; ++i)
    {
        scanf("%d%d", x + i, y + i);
        help[i] = x[i], id[i] = i;
    }
    std::sort(help + 1, help + a + 1);
    int cnt = std::unique(help + 1, help + a + 1) - help - 1;
    for (int i = 1; i <= a; ++i)
        x[i] = std::lower_bound(help + 1, help + cnt + 1, x[i]) - help;
    std::sort(id + 1, id + a + 1, [&](int p, int q){return y[p] < y[q];});
    tree.init(cnt);
    long long ans = 1 + a + b + 1ll * a * b;
    for (int i = 1; i <= a; ++i)
    {
        tree.add(x[id[i]], 1);
        ans += i - tree.query(x[id[i]]);
    }
    for (int i = 1; i <= b; ++i)
    {
        scanf("%d%d", x + i, y + i);
        help[i] = x[i], id[i] = i;
    }
    std::sort(help + 1, help + b + 1);
    cnt = std::unique(help + 1, help + b + 1) - help - 1;
    for (int i = 1; i <= b; ++i)
        x[i] = std::lower_bound(help + 1, help + cnt + 1, x[i]) - help;
    std::sort(id + 1, id + b + 1, [&](int p, int q){return y[p] < y[q];});
    tree.init(cnt);
    for (int i = 1; i <= b; ++i)
    {
        tree.add(x[id[i]], 1);
        ans += i - tree.query(x[id[i]]);
    }
    printf("%lld\n", ans);
    return 0;
}