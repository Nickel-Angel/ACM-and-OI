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

char s[110], c;

inline void solve()
{
    scanf("%s %c", s + 1, &c);
    int n = strlen(s + 1);
    bool flag = false;
    for (int i = 1; i <= n; i += 2)
    {
        if (s[i] == c)
        {
            flag = true;
            break;
        }
    }
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}