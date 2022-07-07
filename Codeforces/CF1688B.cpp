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
int n, a[maxn], cnt[maxn];

inline void solve()
{
    scanf("%d", &n);
    int mi = 40, tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        cnt[i] = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            ++cnt[i];
        }
        if (cnt[i])
            ++tot;
        mi = min(mi, cnt[i]);
    }
    if (tot < n)
        printf("%d\n", tot);
    else
        printf("%d\n", mi + tot - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}