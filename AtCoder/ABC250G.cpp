/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, a[maxn];
std::priority_queue<int, vector<int>, std::greater<int>> q;

int main()
{
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (!q.empty() && q.top() < a[i])
        {
            ans += a[i] - q.top();
            q.pop();
            q.push(a[i]);
        }
        q.push(a[i]);
    }
    printf("%lld\n", ans);
    return 0;
}