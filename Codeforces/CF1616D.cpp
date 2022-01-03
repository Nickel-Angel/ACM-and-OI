#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 5e4 + 10;
int n, a[maxn], x;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    scanf("%d", &x);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= x, ++cnt;
        if (cnt == 1)
            continue;
        if (cnt == 2)
        {
            if (a[i - 1] + a[i] < 0)
            {
                ans += cnt - 1;
                cnt = 0;
            }
            continue;
        }
        if (a[i - 2] + a[i - 1] + a[i] < 0 || a[i - 1] + a[i] < 0)
        {
            ans += cnt - 1;
            cnt = 0;
        }
    }
    ans += cnt;
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