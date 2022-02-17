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

inline void solve()
{
    scanf("%d", &n);
    --n;
    int x = 0;
    while (n >> x)
        ++x;
    --x;
    for (int i = n - 1; i >= 0; --i)
    {
        if (i >> x)
            printf("%d ", i);
        else    
            break;
    }
    printf("%d %d ", n, n ^ (1 << x));
    for (int i = n - 1; i >= 0; --i)
    {
        if (i >> x || (n ^ (1 << x)) == i)
            continue;
        printf("%d ", i);
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