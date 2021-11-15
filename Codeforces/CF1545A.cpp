#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 10;
int n, a[maxn], b[2][maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        b[i & 1][(i + 1) / 2] = a[i];
    }
    std::sort(b[1] + 1, b[1] + (n + 1) / 2 + 1);
    std::sort(b[0] + 1, b[0] + n / 2 + 1);
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = b[i & 1][(i + 1) / 2];
        flag &= (a[i] >= a[i - 1]);
    }
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}