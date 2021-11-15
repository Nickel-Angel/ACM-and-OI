#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 2e5 + 10;
int n, a[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int ans = INT_MIN;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        ans = max(ans, a[i] - a[i - 1]);
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