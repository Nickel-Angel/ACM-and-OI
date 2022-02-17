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

int n, k;
char s[110];

inline void solve()
{
    scanf("%d%d%s", &n, &k, s);
    int l = 0, r = n - 1;
    bool flag = true;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            flag = false;
            break;
        }
        ++l, --r;
    }
    if (flag)
    {
        puts("1");
        return;
    }
    puts(k == 0 ? "1" : "2");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}