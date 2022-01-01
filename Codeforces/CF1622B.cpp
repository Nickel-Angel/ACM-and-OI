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
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, a[maxn];
char s[maxn];
vector<int> sm, la;

inline void solve()
{
    sm.clear(), la.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    scanf("%s", s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '0')
            ++cnt;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '0')
            sm.push_back(i);
        else
            la.push_back(i);
    }
    sort(sm.begin(), sm.end(), [&](int x, int y){return a[x] < a[y];});
    sort(la.begin(), la.end(), [&](int x, int y){return a[x] < a[y];});
    for (unsigned i = 0; i < sm.size(); ++i)
        a[sm[i]] = i + 1;
    for (unsigned i = 0; i < la.size(); ++i)
        a[la[i]] = cnt + i + 1;
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}