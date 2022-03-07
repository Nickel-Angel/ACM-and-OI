/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int maxn = 2e5 + 10;
int n, m, from[maxn << 1], to[maxn << 1], val[maxn << 1], tot;
bool lock[maxn << 1];

std::vector<int> key;

class Union_Find_Set
{
  private:
    int par[maxn], height[maxn];

    inline int find(int x)
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

  public:
    inline void init(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i] = i;
            height[i] = 1;
        }
    }

    inline bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (height[x] < height[y])
            std::swap(x, y);
        par[y] = x;
        height[x] += (height[x] == height[y]);
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", from + i, to + i, val + i);
    int ans = 0;
    for (int i = 30, cnt; i >= 0; --i)
    {
        S.init(n), key.clear();
        cnt = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (lock[j])
                continue;
            if ((val[j] & (1 << i)))
            {
                lock[j] = true;
                key.push_back(j);
                continue;
            }
            if (S.unite(from[j], to[j]))
                ++cnt;
        }
        if (cnt < n - 1)
        {
            ans |= (1 << i);
            for (int j : key)
                lock[j] = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}