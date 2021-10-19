/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::pair;

typedef pair<int, int> P;

const int maxn = 2e5 + 10;
int n, a[maxn], id[maxn];
std::vector<P> ans;

inline void solve()
{
    std::priority_queue<P> q;
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] == 0)
            continue;
        q.push(P(a[i], i));
    }
    P x, y;
    while (!q.empty())
    {
        x = q.top();
        q.pop();
        if (q.empty())
            break;
        y = q.top();
        q.pop();
        --x.first, --y.first;
        ans.push_back(P(x.second, y.second));
        if (x.first > 0)
            q.push(x);
        if (y.first > 0)
            q.push(y);
    }
    printf("%u\n", ans.size());
    for (P e : ans)
        printf("%d %d\n", e.first, e.second);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}