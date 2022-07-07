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

char s[30], t[30];
int n, m;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

inline int find(char *s, int len)
{
    int res = 1;
    bool flag;
    while (res < len)
    {
        if (len % res != 0)
        {
            ++res;
            continue;
        }
        flag = true;
        for (int i = 0, j = 0; i < len; ++i, j = (j + 1) % res)
        {
            if (s[i] != s[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return res;
        ++res;
    }
    return res;
}

inline void solve()
{
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    int mins = find(s, n), mint = find(t, m);
    if (mins != mint)
    {
        puts("-1");
        return;
    }
    for (int i = 0; i < mins; ++i)
    {
        if (s[i] != t[i])
        {
            puts("-1");
            return;
        }
    }
    int cnt = n * m / gcd(n, m) / mins;
    for (int i = 0; i < cnt; ++i)
    {
        for (int j = 0; j < mins; ++j)
            putchar(s[j]);
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