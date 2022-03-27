/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, a[maxn];

std::set<int> s;

inline void solve()
{
    scanf("%d", &n);
    int one = 0;
    s.clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        one += a[i] == 1;
        s.insert(a[i]);
    }
    if (one == 0)
    {
        puts("Yes");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s.count(a[i] + 1))
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}