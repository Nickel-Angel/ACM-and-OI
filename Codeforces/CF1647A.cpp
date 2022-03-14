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
    int cnt1 = n / 3 + (n % 3 == 1), cnt2 = n / 3 + (n % 3 == 2);
    for (int i = 1; i <= n / 3; ++i)
    {
        printf(n % 3 == 1 ? "12" : "21");
    }
    if (n % 3)
        printf("%d\n", n % 3);
    else
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