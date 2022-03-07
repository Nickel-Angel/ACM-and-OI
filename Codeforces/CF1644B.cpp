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

int n, a[60];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        a[i] = n - i + 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("1 ");
        for (int j = i; j < n; ++j)
        {
            printf("%d ", a[j]);
        }
        puts("");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}