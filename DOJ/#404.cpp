/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int m, n, a[maxn], ans[maxn], cnt[maxn], pos[maxn], id[maxn], b;

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        ++cnt[pos[i]];
    for (int i = m - 1; i > 0; --i)
        cnt[i] += cnt[i + 1];
    int cur = 1;
    ans[1] = a[1];
    for (int i = 2, j, l; i <= m; ++i)
    {
        if (id[a[i]])
        {
            if (pos[a[i]] == i)
                b = std::max(b, id[a[i]]);
            continue;
        }
        l = std::max(n - cnt[i], b) + 1;
        j = std::upper_bound(ans + l, ans + cur + 1, a[i]) - ans;
        if (j == cur + 1)
        {
            ans[++cur] = a[i];
            id[a[i]] = cur;
            if (pos[a[i]] == i)
                b = cur;
            continue;
        }
        for (int k = j; k <= cur; ++k)
            id[ans[k]] = 0;
        cur = j, id[a[i]] = j, ans[j] = a[i];
        if (pos[a[i]] == i)
            b = cur;
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= n; ++i)
        printf(" %d", ans[i]);
    return 0;
}