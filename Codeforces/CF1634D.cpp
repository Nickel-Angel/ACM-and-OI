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

inline int query(int i, int j, int k)
{
    printf("? %d %d %d\n", i, j, k);
    fflush(stdout);
    static int res;
    scanf("%d", &res);
    return res;
}

inline void update(int &a, int &b, int x, int y)
{
    static int res[3];
    res[0] = query(a, b, x);
    res[1] = query(a, b, y);
    res[2] = query(a, x, y);
    if (res[0] >= res[1] && res[0] >= res[2])
    {
        if (res[0] == res[1])
            return;
        else if (res[0] == res[2])
            b = x;
        else
            a = x;
    }
    else if (res[1] >= res[2] && res[1] >= res[0])
    {
        if (res[1] == res[2])
            b = y;
        else
            a = y;
    }
    else
    {
        a = x;
        b = y;
    }
}

inline void solve()
{
    scanf("%d", &n);
    int a = 1, b = 2;
    for (int i = 3; i < n; i += 2)
        update(a, b, i, i + 1);
    if (n & 1)
    {
        int pos = 1;
        while (pos == a || pos == b)
            ++pos;
        update(a, b, pos, n);
    }
    printf("! %d %d\n", a, b);
    fflush(stdout);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}