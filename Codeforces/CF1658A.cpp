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

int n;
char s[110];

inline void solve()
{
    scanf("%d%s", &n, s);
    int pre = 0, cur = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            pre = i;
            break;
        }
    }
    for (int i = pre + 1; i < n; ++i)
    {
        if (s[i] == '1')
            ++cur;
        else
        {
            ans += max(2 - cur, 0);
            cur = 0;
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