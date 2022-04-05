/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 2e5 + 10;
int n, p, q, d[maxn];
long long sum[maxn];
std::vector<int> ans;

struct node
{
    int v, id;
}a[maxn];

inline bool check(int x)
{
    for (int i = x; i <= n; ++i)
    {
        if (1ll * x * a[i].v * q <= (sum[i] - sum[i - x]) * p)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].v);
        a[i].id = i;
    }
    std::sort(a + 1, a + n + 1, [&](node x, node y){return x.v < y.v;});
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i].v;
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    int len = l;
    long long s;
    for (int i = len; i <= n; ++i)
    {
        if (1ll * a[i].v * len * q <= p * (sum[i] - sum[i - len]))
        {
            l = 1, r = i - len + 1, s = sum[i] - sum[i - len + 1];
            while (l < r)
            {
                mid = (l + r) >> 1;
                if (1ll * a[i].v * len * q <= p * (s + a[mid].v))
                    r = mid;
                else
                    l = mid + 1;
            }
            ++d[l], --d[i + 1];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        d[i] += d[i - 1];
        if (!d[i])
            ans.push_back(a[i].id);
    }
    std::sort(ans.begin(), ans.end());
    printf("%zu\n", ans.size());
    for (int i : ans)
        printf("%d ", i);
    return 0;
}