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

int x, d;

inline bool isprime(int x)
{
    if (x == 1)
        return true;
    for (int i = 2; 1ll * i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}   

inline void solve()
{
    scanf("%d%d", &x, &d);
    int c = 0;
    while (x % d == 0)
    {
        x /= d;
        ++c;
    }
    if (c <= 1)
    {
        puts("NO");
        return;
    }
    if (!isprime(x))
    {
        puts("YES");
        return;
    }
    if (c == 2 || isprime(d))
    {
        puts("NO");
        return;
    }
    if (1ll * x * x != d || c > 3)
    {
        puts("YES");
        return;
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}