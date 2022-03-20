/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::array;
using std::vector; 

const int maxn = 2e5 + 10;
int n, a[maxn], help[maxn], ans[maxn];

vector<array<int, 3>> q[maxn];

class BIT
{
  private:
    int v[maxn], bound;

    inline int lowbit(int x)
    {
        return x & -x;
    }
   
   public:
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

    inline void build(int n)
    {
        bound = n;
        for (int i = 1; i <= n; ++i)
            v[i] = 0;
    }
}tree;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        help[i] = a[i];
    }
    std::sort(help + 1, help + n + 1);
    int cnt = std::unique(help + 1, help + n + 1) - help - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = std::lower_bound(help + 1, help + cnt + 1, a[i]) - help;
    tree.build(n);
    for (int k = 1; k < n; ++k)
    {
        for (int i = 1, l, r; ; ++i)
        {
            l = k * (i - 1) + 2, r = min(n, k * i + 1);
            if (l > n)
                break;
            q[l - 1].push_back({k, a[i] - 1, -1});
            q[r].push_back({k, a[i] - 1, 1});
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        tree.add(a[i], 1);
        for (auto c : q[i])
        {
            ans[c[0]] += c[2] * tree.query(c[1]);
        }
    }
    for (int k = 1; k < n; ++k)
        printf("%d%c", ans[k], " \n"[k == n - 1]);
    return 0;
}