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
const int p = 1e9 + 7;
int n, a[maxn], pos[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    int l = min(pos[0], pos[1]), r = max(pos[0], pos[1]), ans = 1;
    for (int i = 2; i < n; ++i)
    {
        if (l < pos[i] && pos[i] < r)
            ans = 1ll * ans * (r - l + 1 - i) % p;
        else
        {
            l = min(l, pos[i]);
            r = max(r, pos[i]);
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