/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

int n, d, size[1010], help[1010], cnt;

class Union_Find_Set
{
private:
    int fa[1010], bound, edge;

public:
    inline void init(const int &n)
    {
        bound = n;
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    inline bool unite(int x, int y)
    {
        if (x == 0 || y == 0)
            return false;
        x = find(x), y = find(y);
        if (x == y)
            return false;
        fa[y] = x;
        size[x] += size[y];
        return true;
    }
}S;

int main()
{
    scanf("%d%d", &n, &d);
    S.init(n);
    for (int i = 1; i <= n; ++i)
        size[i] = 1;
    int x, y, ans, safe = 0;
    while (d--)
    {
        scanf("%d%d", &x, &y);
        cnt = 0, ans = 0;
        if (!S.unite(x, y))
            ++safe;
        for (int i = 1; i <= n; ++i)
        {
            if (i == S.find(i))
                help[++cnt] = size[i];
        }
        std::sort(help + 1, help + cnt + 1, std::greater<int>());
        for (int i = 1; i <= safe + 1; ++i)
            ans += help[i];
        printf("%d\n", ans - 1);
    }
    return 0;
}