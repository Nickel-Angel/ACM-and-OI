#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

const int maxn = 2e5 + 10;
int n, m, a[maxn], b[maxn], d[maxn];

inline void solve()
{
    scanf("%d%d", &n, &m);
    long long sum = 0, lower = 0, upper = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", a + i, b + i);
        sum += a[i] - b[i];
        lower+= max(0, m - b[i]), upper += min(a[i], m);
    }
    sum += 1ll * n * m;
    if (2 * lower >= sum)
    {
        printf("%lld\n", 2 * lower - sum);
        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", max(0, m - b[i]), m - max(0, m - b[i]));
        return;
    }
    if (2 * upper <= sum)
    {
        printf("%lld\n", sum - 2 * upper);
        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", min(a[i], m), m - min(a[i], m));
        return;
    }
    printf("%lld\n", sum % 2);
    long long x = (sum >> 1) - lower;
    for (int i = 1, delta; i <= n; ++i)
    {
        d[i] = max(0, m - b[i]);
        delta = min(a[i], m) - max(0, m - b[i]);
        if (x >= delta)
        {
            x -= delta;
            d[i] += delta;
        }
        else
        {
            d[i] += x;
            x = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", d[i], m - d[i]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}