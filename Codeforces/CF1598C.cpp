/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>

const int maxn = 2e5 + 10;
int n, a[maxn];
std::map<int, int> f;

template<typename T>
inline void input(T &x)
{
    x = 0;
    char ch = getchar();
    bool flag = false;
    while (!isdigit(ch))
    {
        flag |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    x = flag ? -x : x;
}

inline void solve()
{
    f.clear();
    input(n);
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        input(a[i]);
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
    input(t);
    while (t--)
        solve();
    return 0;
}