#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

int n, a[80];

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    if (n <= 2)
    {
        puts("0");
        return;
    }
    int ans = n, res;
    for (int i = 1, d, len, t, cnt; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            d = a[i] - a[j];
            t = gcd(abs(d), i - j);
            len = (i - j) / t, d /= t, res = 0, cnt = 1;
            for (int k = i - len, cur = a[i] - d; k > 0; k -= len)
            {
                res += (a[k] != cur);
                cur -= d, ++cnt;
            }
            for (int k = i + len, cur = a[i] + d; k <= n; k += len)
            {
                res += (a[k] != cur);
                cur += d, ++cnt;
            }
            res += n - cnt;
            ans = std::min(ans, res);
        }
        for (int j = i + 1; j <= n; ++j)
        {
            d = a[j] - a[i];
            t = gcd(abs(d), j - i);
            len = (j - i) / t, d /= t, res = 0, cnt = 1;
            for (int k = i - len, cur = a[i] - d; k > 0; k -= len)
            {
                res += (a[k] != cur);
                cur -= d, ++cnt;
            }
            for (int k = i + len, cur = a[i] + d; k <= n; k += len)
            {
                res += (a[k] != cur);
                cur += d, ++cnt;
            }
            res += n - cnt;
            ans = std::min(ans, res);
        }
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