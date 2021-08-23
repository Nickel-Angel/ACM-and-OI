/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;

int n, a[maxn], b[maxn], id[maxn];

class BIT
{
    #define lowbit(x) (x) & -(x)
  private:
    int c[maxn], bound, log_bound;

  public:
    inline void init(int _bound)
    {
        bound = _bound;
        int cnt = 0;
        for (int i = 0; _bound > 0; ++i)
        {
            if ((1 << i) & _bound)
            {
                log_bound = i;
                _bound -= 1 << i;
                ++cnt;
            }
        }
        memset(c, 0, sizeof(c));
    }

    inline void add(int pos, int x)
    {
        for (int i = pos; i <= bound; i += lowbit(i))
            c[i] += x;
    }

    inline int kth(int k)
    {
        int cnt = 0, res = 0;
        for (int i = log_bound; i >= 0; --i)
        {
            res += 1 << i;
            if (res >= n || cnt + c[res] >= k)
                res -= 1 << i;
            else
                cnt += c[res];
        }
        return res + 1;
    }

    #undef lowbit
}tree;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    int cur_n = std::unique(b + 1, b + n + 1) - b - 1, cnt = 0;
    id[++cnt] = b[1];    
    for (int i = 2; i <= cur_n; ++i)
    {
        if (b[i - 1] == b[i])
            continue;
        id[++cnt] = b[i];
    }
    tree.init(cnt);
    for (int i = 1; i <= n; ++i)
    {
        int aft = std::lower_bound(b + 1, b + cur_n + 1, a[i]) - b;
        tree.add(aft, 1);
        if (i & 1)
            printf("%d\n", id[tree.kth((i + 1) / 2)]);
    }
    return 0;
}