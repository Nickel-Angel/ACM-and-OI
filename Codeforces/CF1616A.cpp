#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

int n, a[110], cnt[110];

inline void solve()
{
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[abs(a[i])];
    }
    int ans = !!cnt[0];
    for (int i = 1; i <= 100; ++i)
        ans += std::min(2, cnt[i]);
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