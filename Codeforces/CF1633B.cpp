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
    int cnt = 0;
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        cnt += (s[i] == '0');
    printf("%d\n", n == 2 * cnt ? cnt - 1 : min(cnt, n - cnt));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}