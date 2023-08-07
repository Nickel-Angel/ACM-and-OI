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

char s[2010];
int n, f[2010][2010];

int dfs(int l, int r)
{
    //printf("in %d %d\n", l, r);
    if (l > r)
        return 2;
    if (f[l][r] != -1)
        return f[l][r];
    int &res = f[l][r];
    int ans1, ans2, res1, res2;
    if (s[l] == s[r])
        res1 = dfs(l + 1, r - 1);
    if (s[l] < s[r])
        res1 = dfs(l + 1, r - 1) == 1 ? 1 : 0;
    if (s[l] > s[r])
        res1 = dfs(l + 1, r - 1) == 0 ? 0 : 1;
    if (s[l] == s[l + 1])
        res2 = dfs(l + 2, r);
    if (s[l] < s[l + 1])
        res2 = dfs(l + 2, r) == 1 ? 1 : 0;
    if (s[l] > s[l + 1])
        res2 = dfs(l + 2, r) == 0 ? 0 : 1;
    ans1 = (res1 == 1 || res2 == 1) ? 1 : max(res1, res2);
    if (s[l] == s[r])
        res1 = dfs(l + 1, r - 1);
    if (s[l] < s[r])
        res1 = dfs(l + 1, r - 1) == 0 ? 0 : 1;
    if (s[l] > s[r])
        res1 = dfs(l + 1, r - 1) == 1 ? 1 : 0;
    if (s[r] == s[r - 1])
        res2 = dfs(l, r - 2);
    if (s[r] < s[r - 1])
        res2 = dfs(l, r - 2) == 1 ? 1 : 0;
    if (s[r] > s[r - 1])
        res2 = dfs(l, r - 2) == 0 ? 0 : 1;
    ans2 = (res1 == 1 || res2 == 1) ? 1 : max(res1, res2);
    res = (ans1 == 0 || ans2 == 0) ? 0 : max(ans1, ans2);
    //printf("%d %d %d %d %d\n", l, r, res, ans1, ans2);
    return res;
}

inline void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = -1;
    puts(dfs(1, n) == 2 ? "Draw" : (dfs(1, n) == 0 ? "Alice" : "Bob"));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}