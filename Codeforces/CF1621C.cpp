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

const int maxn = 1e4 + 10;
int n, p[maxn];

inline int query(int i)
{
    printf("? %d\n", i);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        p[i] = 0;
    int pre = 0, cur = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (p[x])
            continue;
        pre = query(x);
        if (x != pre)
        {
            while (x != query(x));
            pre = x;
        }
        while (x != (cur = query(x)))
        {
            p[pre] = cur;
            pre = cur;
        }
        p[pre] = cur;
    }
    printf("! ");
    for (int i = 1; i <= n; ++i)
        printf("%d%c", p[i], " \n"[i == n]);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}