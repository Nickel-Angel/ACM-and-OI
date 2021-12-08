/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

const int maxn = 1e6 + 10;
int n, m;
char s[maxn];

inline void solve()
{
    scanf("%d%d%s", &n, &m, s);
    int len = strlen(s), L = 0, R = 0, U = 0, D = 0, row = 0, column = 0;
    bool flag = false;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == 'R')
        {
            ++column;
            R = max(R, column);
        }
        else if (s[i] == 'L')
        {
            --column;
            L = min(L, column);
        }
        else if (s[i] == 'U')
        {
            --row;
            U = min(U, row);
        }
        else
        {
            ++row;
            D = max(D, row);
        }
        if (R - L + 1 > m)
        {
            flag = true;
            if (s[i] == 'R')
                --R;
            if (s[i] == 'L')
                ++L;
            printf("%d %d\n", n - D, m - R);
            break;
        }
        if (D - U + 1 > n)
        {
            flag = true;
            if (s[i] == 'D')
                --D;
            if (s[i] == 'U')
                ++U;
            printf("%d %d\n", n - D, m - R);
            break;
        }
    }
    if (!flag)
        printf("%d %d\n", n - D, m - R);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}