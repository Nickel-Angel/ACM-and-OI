/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int t, n, a[maxn], cave[maxn], size[maxn], id[maxn];

bool cmp(int x, int y)
{
    return cave[x] < cave[y];
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", size + i);
            cave[i] = 0;
            for (int j = 0, x; j < size[i]; ++j)
            {
                scanf("%d", &x);
                cave[i] = std::max(cave[i], x - j + 1);
            }
            id[i] = i;
        }
        std::sort(id + 1, id + n + 1, cmp);
        int sum = size[id[1]];
        int power = cave[id[1]] + size[id[1]], ans = cave[id[1]];
        for (int i = 2; i <= n; ++i)
        {
            if (power < cave[id[i]])
            {
                ans = cave[id[i]] - sum;
                power = cave[id[i]];
            }
            sum += size[id[i]];
            power += size[id[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}