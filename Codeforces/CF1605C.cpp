#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 1e6 + 10;
int n;
char s[maxn];

inline void solve()
{
    scanf("%d%s", &n, s + 1);
    int ans = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] != 'a')
            continue;
        for (int j = i + 1, a = 1, b = 0, c = 0; j <= min(i + 7, n); ++j)
        {
            a += (s[j] == 'a');
            b += (s[j] == 'b');
            c += (s[j] == 'c');
            if (b < a && c < a)
            {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    printf("%d\n", ans == n + 1 ? -1 : ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}