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

const int p = 1e9 + 7;
const int maxn = 5e5 + 10;
int n, pre[maxn], suf[maxn], base[maxn];
char s[maxn];

inline bool check(int l, int r)
{
    return ((pre[r] - 1ll * pre[l - 1] * base[r - l + 1] % p) + p) % p ==
    (suf[l] - 1ll * suf[r + 1] * base[r - l + 1] % p + p) % p;
}

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i)
        pre[i] = (26ll * pre[i - 1] % p + (s[i] == '(')) % p; 
    for (int i = n; i > 0; --i)
        suf[i] = (26ll * suf[i + 1] % p + (s[i] == '(')) % p;
    int l = 1, c = 0, cur = 0;
    bool lock = false;
    for (int i = 1; i <= n; ++i)
    {
        if (i - l > 0 && check(l, i))
        {
            ++c, cur = 0;
            lock = false;
            l = i + 1;
            continue;
        }
        if (lock)
            continue;
        if (s[i] == ')')
        {
            if (!cur)
            {
                lock = true;
                continue;
            }
            else
                --cur;
        }
        if (s[i] == '(')
            ++cur;
        if (!cur)
        {
            ++c, l = i + 1;
            lock = false;
        }
    }
    printf("%d %d\n", c, n - l + 1);
}

int main()
{
    base[0] = 1;
    for (int i = 1; i <= maxn - 10; ++i)
        base[i] = 1ll * base[i - 1] * 26 % p;
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}