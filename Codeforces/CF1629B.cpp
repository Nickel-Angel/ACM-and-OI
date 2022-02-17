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

int l, r, k;

inline void solve()
{
    scanf("%d%d%d", &l, &r, &k);
    if (l == r)
    {
        puts(l == 1 ? "NO" : "YES");
        return;
    }
    int len;
    if ((r - l + 1) % 2 == 0)
        len = (r - l + 1) / 2;
    else
        len = (l % 2 == 0) ? (r - l + 1) / 2 : (r - l + 1) / 2 + 1;
    puts(len <= k ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}