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

const int maxn = 1e5 + 10;
int n;
char s[maxn], t[maxn];

inline void solve()
{
    scanf("%d%s%s", &n, s, t);
    int b = 0, c = 0;
    for (int i = 0; i < n; ++i)
    {
        b = max(b, i), c = max(c, i);
        while (b < n && s[b] != 'b' && s[b] != 'c')
            ++b;
        while (c < n && s[c] != 'c' && s[c] != 'a')
            ++c;
        if (s[i] == t[i])
            continue;
        if (t[i] == 'a')
        {
            puts("NO");
            return;
        }
        if (t[i] == 'b')
        {
            if (s[b] != 'b')
            {
                puts("NO");
                return;
            }
            else
                swap(s[i], s[b]);
            continue;
        }
        if (s[c] != 'c')
        {
            puts("NO");
            return;
        }
        swap(s[i], s[c]);
    }
    puts("YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}