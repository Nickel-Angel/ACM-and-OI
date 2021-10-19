/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;

int n, a[110];

inline bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

inline void solve()
{
    scanf("%d", &n);
    int sum = 0, key = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum += a[i];
        if (a[i] & 1)
            key = i;
    }
    if (!isprime(sum))
    {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%d ", i);
    }
    else
    {
        printf("%d\n", n - 1);
        for (int i = 1; i <= n; ++i)
        {
            if (key == i)
                continue;
            printf("%d ", i);
        }
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();    
    return 0;
}