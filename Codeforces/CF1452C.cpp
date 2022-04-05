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

const int maxn = 2e5 + 10;
int n;
char s[maxn];

inline void solve()
{
    scanf("%s", s);
    n = strlen(s);
    int tot1 = 0, tot2 = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
            ++tot1;
        if (s[i] == ')')
        {
            if (tot1)
            {
                --tot1;
                ++ans;
            }
        }
        if (s[i] == '[')
            ++tot2;
        if (s[i] == ']')
        {
            if (tot2)
            {
                --tot2;
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}