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

const int maxn = 2e5 + 10;
int n, m, cnt[maxn];
ll ans[maxn];
vector<int> vec[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= n; ++i)
    {
        scanf("%d%d", &x, &y);
        vec[x].push_back(i);
        vec[y].push_back(i);
    }
    int cur = 0;
    for (int r = 1, l = 1; r <= m; ++r)
    {
        for (int x : vec[r])
        {
            if (cnt[x] == 0)
                ++cur;
            ++cnt[x];
        }
        if (cur == n)
        {
            while (l <= r && cur == n)
            {
                ++ans[r - l + 1];
                --ans[m - l + 2];
                for (int x : vec[l])
                {
                    if (cnt[x] == 1)
                        --cur;
                    --cnt[x];
                }
                ++l;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        ans[i] += ans[i - 1];
        printf("%lld%c", ans[i], " \n"[i == m]);
    }
    return 0;
}