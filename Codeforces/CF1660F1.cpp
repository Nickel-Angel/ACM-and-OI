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

int n, sum[3010], minus[3010], tag[3010];
char s[3010];

inline void solve()
{
    memset(tag, 0, sizeof(tag));
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + (s[i] == '+');
        if (s[i] == '-')
        {
            if (s[i - 1] == '-' && tag[i - 1] == 0)
            {
                tag[i - 1] = 1;
                tag[i] = 2;
                minus[i] = minus[i - 1] + 1;
            }
            else
                minus[i] = minus[i - 1];
        }
        else
            minus[i] = minus[i - 1];
    }
    int ans = 0;
    for (int i = 1, tot; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            //printf("%d %d\n", sum[j] - sum[i - 1], j - i + 1);
            if (2 * (sum[j] - sum[i - 1]) > j - i + 1)
                continue;
            if ((j - i + 1 - 2 * (sum[j] - sum[i - 1])) % 3 == 0)
            {
                tot = minus[j] - minus[i - 1];
                if (tag[i] == 2)
                    --tot;
                ans += ((j - i + 1 - 2 * (sum[j] - sum[i - 1])) / 3 <= tot);
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