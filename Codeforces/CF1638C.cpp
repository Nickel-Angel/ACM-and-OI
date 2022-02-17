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

const int maxn = 1e5 + 10;
int n, p[maxn], s[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", p + i);
    int ans = 0;
    for (int i = 1, t; i <= n; ++i)
    {
        if (s[ans] < p[i] || !ans)
            s[++ans] = p[i];
        else
        {
            t = s[ans];
            while (ans && p[i] < s[ans])
                --ans;
            s[++ans] = t;
        }
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