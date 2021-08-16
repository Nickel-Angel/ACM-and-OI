/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

typedef std::pair<int, int> P;

const int maxn = 1010;
int n, m1, m2;
P ans[maxn * maxn];

class Union_Find_Set
{
  private:
    int fa[maxn], size[maxn], _bound;

    int find(int x)
    {
        return x = ((x == fa[x]) ? x : find(fa[x])); 
    }

  public:
    inline void init(int bound)
    {
        _bound = bound;
        for (int i = 1; i <= _bound; ++i)
        {
            fa[i] = i;
            size[i] = 1;
        }
    }

    inline bool unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (size[fx] < size[fy]) std::swap(fx, fy);
        fa[fx] = fy, size[fy] += size[fx];
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S, T;

int main()
{
    scanf("%d", &n);
    S.init(n), T.init(n);
    scanf("%d%d", &m1, &m2);
    for (int i = 1, u, v; i <= m1; ++i)
    {
        scanf("%d%d", &u, &v);
        S.unite(u, v);
    }
    
    for (int i = 1, u, v; i <= m2; ++i)
    {
        scanf("%d%d", &u, &v);
        T.unite(u, v);
    }
    int h = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (S.judge(i, j) || T.judge(i, j)) continue;
            ans[++h] = P(i, j);
            S.unite(i, j), T.unite(i, j);
        }
    }
    printf("%d\n", h);
    for (int i = 1; i <= h; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}