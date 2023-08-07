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

const int maxn = 1e6 + 10;
const int p = 1e9 + 7;
char s[maxn];
int t, n, next[maxn], f[maxn];

inline void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    f[1] = 1;
    int ans = 1;
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && s[j + 1] != s[i])
            j = next[j];
        if (s[j + 1] == s[i])
            ++j;
        next[i] = j;
        f[i] = f[next[i]] + 1;
    }
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && s[j + 1] != s[i])
            j = next[j];
        if (s[j + 1] == s[i])
            ++j;
        while (j * 2 > i)
            j = next[j];
        ans = 1ll * ans * (f[j] + 1) % p;
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}