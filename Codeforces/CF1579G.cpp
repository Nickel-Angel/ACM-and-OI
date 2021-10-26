/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>

int n, a[10010];
std::bitset<2010> lim, cur;

inline void print(const std::bitset<2010>& a, int x)
{
    for (int i = 0; i < x; ++i)
        printf("%d%c", a[i], " \n"[i == x - 1]);
}

inline bool check(int x)
{
    lim.reset(), cur.reset();
    for (int i = 0; i < x; ++i)
    {
        lim.set(i);
        cur.set(i);
    }
    for (int i = 1; i <= n; ++i)
        cur = ((cur << a[i]) | (cur >> a[i])) & lim;
    return cur.any();
}

inline void solve()
{
    scanf("%d", &n);
    int len = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        len = std::max(len, a[i]);
    }
    int s = 1, e = 2 * len + 2, mid, ans = e;
    while (s <= e)
    {
        mid = (s + e) >> 1;
        if (check(mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    printf("%d\n", ans - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}