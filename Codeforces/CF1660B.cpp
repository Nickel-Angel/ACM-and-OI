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
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    int M = 0, m = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (M <= a[i])
        {
            m = M;
            M = a[i];
        }
        else
            m = max(m, a[i]);
    }
    if (n == 1)
    {
        puts(a[1] == 1 ? "Yes" : "No");
        return;
    }
    puts(M - m <= 1 ? "Yes" : "No");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}