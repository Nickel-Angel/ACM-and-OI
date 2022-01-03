/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e7;
int p[maxn + 10], next[maxn + 10], tot = 0;
bool vis[maxn + 10];

inline bool check(int x)
{
    while (x)
    {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

inline void calc()
{
    for (int i = 7; i <= maxn; ++i)
    {
        if (check(i))
        {
            p[++tot] = i;
            if (vis[i])
                continue;
            vis[i] = true;
            for (int j = 2; i * j <= maxn + 1; ++j)
                vis[i * j] = true;
        }
    }
    for (int i = 1, j = 1; i <= maxn + 1; ++i)
    {
        if (!vis[i])
        {
            next[j] = i;
            j = i;
        }
        else
            next[i] = -1;
    }
}

int main()
{
    calc();
    int t, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &x);
        printf("%d\n", next[x]);
    }
    return 0;
}