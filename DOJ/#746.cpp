/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, a[110], b[110], id[110];

inline void solve()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", a + i, b + i);
        id[i] = i, sum += b[i];
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return a[x] == a[y] ? b[x] < b[y] : a[x] > a[y];});
    if (n == 2)
    {
        puts("Yes");
        return;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (sum - b[id[i]] + a[id[i]] > a[id[i - 1]])
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}