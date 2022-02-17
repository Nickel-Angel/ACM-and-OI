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

const int maxn = 2e5 + 10;
int n, m;

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
        for (int i = 1; i <= bound; ++i)
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
        if (height[x] > height[y])
            swap(x, y);
        par[x] = y;
        height[y] += (height[x] == height[y]);
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
    S.init(n);
    for (int i = 1, l, r; i <= m; ++i)
    {
        scanf("%d%d", &l, &r);
        S.unite(l - 1, r);
    }
    puts(S.judge(0, n) ? "Yes" : "No");
    return 0;
}