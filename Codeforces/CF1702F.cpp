/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <set>

const int maxn = 2e5 + 10;
int n;
std::multiset<int> a, b;

inline void solve()
{
    a.clear(), b.clear();
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        while (x % 2 == 0)
            x /= 2;
        a.insert(x);
    }
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        b.insert(x);
    }
    int x;
    while (!b.empty())
    {
        x = *(--b.end());
        b.erase(--b.end());
        while (x)
        {
            auto it = a.find(x);
            if (it != a.end())
            {
                a.erase(it);
                break;
            }
            x /= 2;
        }
        if (!x)
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}