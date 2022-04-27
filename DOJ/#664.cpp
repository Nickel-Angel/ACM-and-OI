/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int d, m;

inline void solve()
{
    scanf("%d%d", &d, &m);
    int ans = 1;
    long long cur = 0;
    for (int i = 0; i < 32; ++i)
    {
        cur += (1ll << i);
        if (cur < d)
            ans = 1ll * ans * ((1 << i) + 1) % m;
        else if (cur == d)
        {
            ans = 1ll * ans * ((1 << i) + 1) % m;
            break;
        }
        else
        {
            cur -= (1ll << i);
            ans = 1ll * ans * (d - cur + 1) % m;
            break;
        }
    }
    printf("%d\n", (ans + m - 1) % m);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}