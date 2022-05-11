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
char s[maxn];

inline void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    if (n == 1)
    {
        printf("Bob %d\n", s[0] - 'a' + 1);
        return;
    }
    if (n % 2 == 0)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += s[i] - 'a' + 1;
        printf("Alice %d\n", ans);
        return;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
        ans += s[i] - 'a' + 1;
    if (ans + max(s[0], s[n - 1]) > min(s[0], s[n - 1]))
    {
        printf("Alice %d\n", ans + max(s[0], s[n - 1]) - min(s[0], s[n - 1]));
    }
    else
    {
        printf("Bob %d\n", min(s[0], s[n - 1]) - ans - max(s[0], s[n - 1]));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}