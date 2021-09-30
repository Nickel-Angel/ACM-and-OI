/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using std::min;
using std::max;
using std::priority_queue;

const int maxn = 1e5 + 10;
int n, m, a[maxn];
long long kth[maxn];

priority_queue<int, std::vector<int>, std::greater<int> > q;

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    if (m == 2)
    {
        long long sum = 0, ans = a[1] + a[2];
        for (int i = 2; i < n; ++i)
        {
            sum += min(a[i], a[i - 1]);
            ans = max(ans, a[1] - sum + a[i + 1]);
        }
        printf("%lld\n", ans);
        return;
    }
    m -= 2;
    while (!q.empty())
        q.pop();
    long long ans = 0, sum = 0;
    for (int i = 0; i < m; ++i)
    {
        sum += a[n - i];
        q.push(a[n - i]);
    }
    kth[n - m + 1] = sum;
    for (int i = n - m; i > 0; --i)
    {
        q.push(a[i]);
        sum += a[i] - q.top();
        kth[i] = sum;
        q.pop();
    }
    sum = 0, ans = a[1] + a[2] + kth[3];
    for (int i = 1; i < n - m; ++i)
    {
        ans = max(ans, a[1] - sum + a[i + 1] + kth[i + 2]);
        sum += min(a[i], a[i + 1]);
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%*d%d", &t);
    while (t--)
        solve();
    fclose(stdin);
    return 0;
}