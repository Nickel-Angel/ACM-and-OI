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

const int maxn = 2e5 + 10;
int n, cnt[maxn][26], pre[maxn], cur[26];
bool vis[26];
char s[maxn];

inline int calc(int l, int r)
{
    int res = 2;
    for (int i = 0; i < 26; ++i)
    {
        if (vis[i])
        {
            res = min(res, cnt[r][i] - cnt[l - 1][i]);
        }
    }
    return res;
}

inline void solve()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(vis, false, sizeof(vis));
    memset(cur, 0, sizeof(cur));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            cnt[i][j] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[i][s[i] - 'a'] = 1;
        pre[i] = cur[s[i] - 'a'];
        cur[s[i] - 'a'] = i;
        vis[s[i] - 'a'] = true;
        for (int j = 0; j < 26; ++j)
            cnt[i][j] += cnt[i - 1][j];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (!vis[i])
            continue;
        for (int j = cur[i]; pre[j]; j = pre[j])
        {
            //printf("%d %d %d\n", pre[j], j, calc(pre[j], j));
            if (calc(pre[j], j) < 1)
            {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}