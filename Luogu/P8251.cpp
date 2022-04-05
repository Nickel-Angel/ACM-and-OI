/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

const int maxn = 5e5 + 10;
int n, q, a[maxn], b[maxn], f[maxn][21];
int s[maxn], top;

template<typename T>
inline void input(T &x)
{
    x = 0;
    char ch = getchar();
    bool f = false;
    while (!isdigit(ch))
    {
        ch = getchar();
        f |= (ch == '-');
    }
    while (isdigit(ch))
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x = f ? -x : x;
}

int main()
{
    input(n), input(q);
    for (int i = 1; i <= n; ++i)
        input(a[i]);
    for (int i = 1; i <= n; ++i)
        input(b[i]);
    for (int i = 1; i <= n; ++i)
    {
        while (top && (b[s[top]] <= b[i] || a[s[top]] == a[i]))
        {
            f[s[top]][0] = i;
            --top;
        }
        s[++top] = i;
    }
    for (int j = 1; j <= 20; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    int l, r, ans;
    while (q--)
    {
        input(l), input(r);
        ans = 0;
        for (register int i = 20; i >= 0; --i)
        {
            if (f[l][i] <= r && f[l][i])
            {
                ans |= (1 << i);
                l = f[l][i];
            }
        }
        ++ans;
        printf("%d\n", ans);
    }
    return 0;
}