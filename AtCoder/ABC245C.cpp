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
int n, k, a[maxn], b[maxn];

class Union_Find_Set
{
  private:
    int par[maxn << 1];

    int find(int x)
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

  public:
    inline void init(int n)
    {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }

    inline bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        par[x] = y;
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    S.init(2 * n);
    for (int i = 1; i < n; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= k)
            S.unite(i, i + 1);
        if (abs(a[i] - b[i + 1]) <= k)
            S.unite(i, i + n + 1);
        if (abs(b[i] - a[i + 1]) <= k)
            S.unite(i + n, i + 1);
        if (abs(b[i] - b[i + 1]) <= k)
            S.unite(i + n, i + n + 1);
    }
    puts((S.judge(1, n) || S.judge(1, 2 * n) || S.judge(1 + n, n) || S.judge
    (1 + n, 2 * n)) ? "Yes" : "No");
    return 0;
}