/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

const int maxn = 1e5 + 10;
int n, help[maxn], d[maxn], p[maxn]; 
std::vector<int> work[maxn];
std::priority_queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", d + i, p + i);
        if (d[i] == 0)
            --i, --n;
        help[i] = d[i];
    }
    std::sort(help + 1, help + n + 1);
    int cnt = std::unique(help + 1, help + n + 1) - help - 1;
    for (int i = 1; i <= n; ++i)
        work[std::lower_bound(help + 1, help + cnt + 1, d[i]) - help].push_back(p[i]);
    long long ans = 0;
    for (int i = cnt; i > 0; --i)
    {
        for (int j : work[i])
            q.push(j);
        for (int j = 0; j < help[i] - help[i - 1] && !q.empty(); ++j)
        {
            ans += q.top();
            q.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}