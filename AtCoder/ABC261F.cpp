/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 3e5 + 10;
int n, c[maxn], a[maxn];
vector<int> color[maxn];

class BIT
{
  private:
    int v[maxn], tag[maxn], tim;

    inline int lowbit(int x)
    {
        return x & -x;
    }

  public:
    inline void clear()
    {
        ++tim;
    }
    
    inline void add(int pos, int x)
    {
        for (int i = pos; i <= n; i += lowbit(i))
        {
            if (tag[i] != tim)
            {
                v[i] = 0;
                tag[i] = tim;
            }
            v[i] += x;
        }
    }

    inline int query(int pos)
    {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
        {
            if (tag[i] != tim)
            {
                v[i] = 0;
                tag[i] = tim;
            }
            res += v[i];
        }
        return res;
    }
}tree;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", c + i);
        color[c[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += i - 1 - tree.query(a[i]);
        tree.add(a[i], 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        tree.clear();
        for (int j = 0; j < (int)color[i].size(); ++j)
        {
            ans -= j - tree.query(a[color[i][j]]);
            tree.add(a[color[i][j]], 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}