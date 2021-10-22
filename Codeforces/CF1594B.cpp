/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 1e9 + 7;
int n, k;

inline void solve()
{
    scanf("%d%d", &n, &k);
    int ans = 0, base = 1;
    while (k)
    {
        if (k & 1)
            ans = (ans + base) % p;
        base = 1ll * base * n % p;
        k >>= 1;
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