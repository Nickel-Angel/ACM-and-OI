/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;

class Union_Find_Set
{
  private:
    int par[maxn], height[maxn], bound;

    int find(int x)
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

  public:
    inline void init(int n)
    {
        bound = n;
        for (int i = 1; i <= n; ++i)
        {
            par[i] = i;
            height[i] = 1;
        }
    }

    inline bool unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return false;
        if (height[fx] < height[fy])
            std::swap(fx, fy);
        par[fy] = fx;
        height[fx] = std::max(height[fx], height[fy] + 1);
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S;

int n, m, u[maxn], v[maxn], w[maxn];
bool lock[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", u + i, v + i, w + i);
        lock[i] = false;
    }
    int ans = 0;
    for (int i = 30; i >= 0; --i)
    {
        S.init(n);
        for (int j = 1; j <= m; ++j)
        {
            if (lock[j] || ((w[j] >> i) & 1))
                continue;
            S.unite(u[j], v[j]);
        }
        bool flag = true;
        for (int j = 2; j <= n; ++j)
            flag &= S.judge(1, j);
        if (!flag)
            ans |= (1 << i);
        else
        {
            for (int j = 1; j <= m; ++j)
            {
                if ((w[j] >> i) & 1)
                    lock[j] = true;
            }
        }
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