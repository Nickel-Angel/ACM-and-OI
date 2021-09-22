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

const int maxn = 2e5 + 10;
std::vector<int> ans;
int n, a[maxn];

inline void set(int i, int x)
{
    ans.push_back(i);
    a[i] = x, a[i + 1] = x, a[i + 2] = x;
}

inline bool check(int i)
{
    if (i + 2 > n)
        return false;
    if (a[i] + a[i + 1] + a[i + 2] == 2)
        set(i, 0);
    if (!a[i])
        return true;
    if (a[i])
    {
        if (a[i + 1] + a[i + 2] == 0)
            set(i, 1);
        if (check(i + 2))
        {
            set(i, 0);
            return true;
        }
    }
    return false;
}

inline void solve()
{
    ans.clear();
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        tot += a[i];
    }
    if (tot & 1)
    {
        puts("NO");
        return;
    }
    for (int i = 1; i <= n - 2; ++i)
    {
        if (!check(i))
            break;
    }
    for (int i = 1; i <= n - 2; ++i)
    {
        if (!check(i))
        {
            puts("NO");
            return;
        }
    }
    printf("YES\n%u\n", ans.size());
    for (auto c : ans)
        printf("%d ", c);
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