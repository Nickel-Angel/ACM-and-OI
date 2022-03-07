/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int maxn = 5e5 + 10;
int n, a[maxn], s[maxn][2], top[2];
int pre[maxn][2], next[maxn][2];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        while (top[0] && a[s[top[0]][0]] > a[i])
            --top[0];
        pre[i][0] = s[top[0]][0];
        if (!pre[i][0])
            pre[i][0] = 0;
        s[++top[0]][0] = i;
        while (top[1] && a[s[top[1]][1]] < a[i])
            --top[1];
        pre[i][1] = s[top[1]][1];
        if (!pre[i][1])
            pre[i][1] = 0;
        s[++top[1]][1] = i;
    }
    top[0] = top[1] = 0;
    for (int i = n; i > 0; --i)
    {
        while (top[0] && a[s[top[0]][0]] >= a[i])
            --top[0];
        next[i][0] = s[top[0]][0];
        if (!next[i][0])
            next[i][0] = n + 1;
        s[++top[0]][0] = i;
        while (top[1] && a[s[top[1]][1]] <= a[i])
            --top[1];
        next[i][1] = s[top[1]][1];
        if (!next[i][1])
            next[i][1] = n + 1;
        s[++top[1]][1] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += 1ll * (i - pre[i][0]) * (next[i][0] - i) * -a[i];
        ans += 1ll * (i - pre[i][1]) * (next[i][1] - i) * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}