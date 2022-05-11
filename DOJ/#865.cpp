/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, m;

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
            v[i] += x;
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            res += v[i];
        return res;
    }

    inline int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
}pre, last;

int main()
{
    scanf("%d%d", &n, &m);
    pre.init(n), last.init(n);
    int opt, l, r;
    while (m--)
    {
        scanf("%d%d%d", &opt, &l, &r);
        if (opt == 1)
        {
            pre.add(l, 1);
            last.add(n, -1);
            last.add(r, 1);
        }
        else
        {
            printf("%d\n", pre.query(r) + last.query(l, n));
        }
    }
    return 0;
}