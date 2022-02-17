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
int n;
ll x, y;

inline void solve()
{
    scanf("%d%lld%lld", &n, &x, &y);
    int flag = 0;
    for (int i = 1, a; i <= n; ++i)
    {
        scanf("%d", &a);
        flag ^= (a & 1);
    }
    puts(((x & 1) ^ flag) == (y & 1) ? "Alice" : "Bob");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}