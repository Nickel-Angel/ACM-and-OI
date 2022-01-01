/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
int n, m, k, p[maxn];

inline void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1, cur, size; i <= k; ++i)
    {
        cur = 1;
        for (int j = 0; j < m; ++j)
        {
            size = j < n % m ? n / m + 1 : n / m;
            printf("%d ", size);
            while (size--)
            {
                printf("%d ", p[cur]);
                ++cur;        
            }
            puts("");
        }
        std::rotate(p + 1, p + (n % m) * ((n + m - 1) / m) + 1, p + n + 1);
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}