/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

const int maxn = 2e5 + 10;
const int bound = 4e5 + 5;
const int p = 998244353;

int n, m, y[maxn], fac[bound], inv_fac[bound], del[maxn];
std::set<int> tag;

class BIT
{
    #define lowbit(x) ((x) & -(x))
  private:
    int c[maxn], bound, log_bound;

  public:
    inline void build(int _bound)
    {
        for (int i = 1, j; i <= _bound; ++i)
        {
            c[i] += 1;
            j = i + lowbit(i);
            if (j <= _bound)
                c[j] += c[i];
        }
    }

    inline void init(int _bound)
    {
        bound = _bound;
        for (int i = 0; _bound > 0; ++i)
        {
            if (_bound & (1 << i))
            {
                _bound -= 1 << i;
                log_bound = i;
            }
        }
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
            c[i] += x;
    }

    inline int kth(int k)
    {
        int res = 0, cnt = 0;
        for (int i = log_bound; i >= 0; --i)
        {
            res += 1 << i;
            if (res >= bound || cnt + c[res] >= k)
                res -= 1 << i;
            else
                cnt += c[res];
        }
        return res + 1;
    }
    #undef lowbit
}tree;

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return res;
}

inline int C(int a, int b)
{
    if (a < b)
        return 0;
    return 1ll * fac[a] * inv_fac[b] % p * inv_fac[a - b] % p;
}

int main()
{
    fac[0] = 1;
    for (int i = 1; i <= bound - 5; ++i)
        fac[i] = 1ll * fac[i - 1] * i % p;
    inv_fac[bound - 5] = power(fac[bound - 5], p - 2);
    for (int i = bound - 5; i > 0; --i)
        inv_fac[i - 1] = 1ll * inv_fac[i] * i % p;
    tree.build(maxn - 5);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        tag.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1, x; i <= m; ++i)
            scanf("%d%d", &x, y + i);
        tree.init(n);
        for (int i = m; i > 0; --i)
        {
            int p = tree.kth(y[i]);
            int q = tree.kth(y[i] + 1);
            tree.add(p, -1);
            del[i] = p, tag.insert(q);
        }
        for (int i = 1; i <= m; ++i)
            tree.add(del[i], 1);
        int c = tag.size();
        printf("%d\n", C(n * 2 - c - 1, n));
    }
    return 0;
}