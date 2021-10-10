/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

typedef long long ll;

const int maxc = 2e5 + 10;
const int maxm = 1e5 + 10;
int n, m;
int c[15], a[15][maxc], sum[maxm];
std::map<std::vector<int>, bool> ban;
std::vector<int> ans, help, b[maxm];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", c + i);
        for (int j = 1; j <= c[i]; ++j)
            scanf("%d", a[i] + j);
    }
    scanf("%d", &m);
    if (m == 0)
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", c[i]);
        return 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0, x; j < n; ++j)
        {
            scanf("%d", &x);
            sum[i] += a[j][x];
            b[i].push_back(x);
        }
        ban[b[i]] = true;
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            help = b[i];
            if (help[j] == 1)
                continue;
            --help[j];
            if (ban.find(help) != ban.end())
                continue;
            if (sum[i] - a[j][help[j] + 1] + a[j][help[j]] > res)
            {
                res = sum[i] - a[j][help[j] + 1] + a[j][help[j]];
                ans = help;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        help[i] = c[i];
    if (ban.find(help) == ban.end())
        ans = help;
    for (int e : ans)
        printf("%d ", e);
    return 0;
}