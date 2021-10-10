/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_map>

const int maxn = 2e5 + 10;
int n, a[maxn];
std::unordered_map<int, int> f;

inline void solve()
{
    f.clear();
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        sum += a[i];
    }
    if (sum * 2 % n != 0)
    {
        puts("0");
        return;
    }
    int x = sum * 2 / n;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += f[x - a[i]];
        ++f[a[i]];
    }
    printf("%lld\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}