/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxa = (1 << 13);
std::vector<int> g[maxa], ans;
int n, r[maxa];
bool vis[maxa];

int main()
{
    scanf("%d", &n);
    vis[0] = true;
    for (int i = 0; i < maxa; ++i)
    {
        g[i].push_back(0);
        r[i] = maxa;
    }
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        for (int e : g[x])
        {
            int sum = e ^ x;
            vis[sum] = true;
            while (x < r[sum])
            {
                --r[sum];
                if (r[sum] != x)
                    g[r[sum]].push_back(sum);
            }
        }
        g[x].clear();
    }
    for (int i = 0; i < maxa; ++i)
    {
        if (vis[i])
            ans.push_back(i);
    }
    printf("%zu\n", ans.size());
    for (int e : ans)
        printf("%d ", e);
    return 0;
}