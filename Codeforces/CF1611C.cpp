/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::deque;

const int maxn = 2e5 + 10;
int n, a[maxn];
deque<int> q;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int l = 1, r = n;
    if (a[l] != n && a[r] != n)
    {
        puts("-1");
        return;
    }
    while (l <= r)
    {
        if (a[l] < a[r])
        {
            q.push_front(a[l]);
            ++l;
        }
        else
        {
            q.push_back(a[r]);
            --r;
        }
    }
    while (!q.empty())
    {
        printf("%d ", q.front());
        q.pop_front();
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