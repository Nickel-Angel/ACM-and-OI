/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e5 + 10;
int n, a[maxn], st[maxn][21][2], pos[maxn][21][2], log_2[maxn], r[maxn][2], s[maxn], top;

inline int query_min(int l, int r)
{
    int k = log_2[r - l + 1];
    return st[l][k][0] < st[r - (1 << k) + 1][k][0] ? pos[l][k][0] : pos[r - (1 << k) + 1][k][0];
}

inline int query_max(int l, int r)
{
    int k = log_2[r - l + 1];
    return st[l][k][1] > st[r - (1 << k) + 1][k][1] ? pos[l][k][1] : pos[r - (1 << k) + 1][k][1];
}

inline void solve()
{
    scanf("%d", &n);
    log_2[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        st[i][0][0] = a[i], pos[i][0][0] = i;
        st[i][0][1] = a[i], pos[i][0][1] = i;
        log_2[i] = log_2[i >> 1] + 1;
    }
    log_2[0] = 0;
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            if (st[i][j - 1][0] < st[i + (1 << (j - 1))][j - 1][0])
            {
                st[i][j][0] = st[i][j - 1][0];
                pos[i][j][0] = pos[i][j - 1][0];
            }
            else
            {
                st[i][j][0] = st[i + (1 << (j - 1))][j - 1][0];
                pos[i][j][0] = pos[i + (1 << (j - 1))][j - 1][0];
            }
            if (st[i][j - 1][1] > st[i + (1 << (j - 1))][j - 1][1])
            {
                st[i][j][1] = st[i][j - 1][1];
                pos[i][j][1] = pos[i][j - 1][1];
            }
            else
            {
                st[i][j][1] = st[i + (1 << (j - 1))][j - 1][1];
                pos[i][j][1] = pos[i + (1 << (j - 1))][j - 1][1];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        while (top && a[s[top]] > a[i])
        {
            r[s[top]][0] = i - 1;
            --top;
        }
        s[++top] = i;
    }
    while (top)
    {
        r[s[top]][0] = n;
        --top;
    }
    for (int i = 1; i <= n; ++i)
    {
        while (top && a[s[top]] < a[i])
        {
            r[s[top]][1] = i - 1;
            --top;
        }
        s[++top] = i;
    }
    while (top)
    {
        r[s[top]][1] = n;
        --top;
    }
    for (int i = 1; i <= n; ++i)
    {
        //printf("%d %d\n", r[i][0], r[i][1]);
        r[i][0] = query_max(i, r[i][0]);
        r[i][1] = query_min(i, r[i][1]);
    }
    int cur = 1, ans = 0;
    while (cur < n)
    {
        cur = std::max(r[cur][0], r[cur][1]);
        ++ans;
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}