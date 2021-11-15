#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::pair;

typedef pair<int, int> P;

int n, m, f[2010][2010], top, ans, ans_x, ans_y;
char s[2010][2010];
bool vis[2010][2010], flag;
P stk[4000010];

int dfs(int x, int y)
{
    stk[++top] = P(x, y);
    if (x <= 0 || y <= 0 || x > n || y > m)
        return 0;
    if (vis[x][y])
    {
        flag = true;
        return 0;
    }
    vis[x][y] = true;
    if (f[x][y])
        return f[x][y];
    int res = 0;
    if (s[x][y] == 'L')
        res = dfs(x, y - 1);
    if (s[x][y] == 'R')
        res = dfs(x, y + 1);
    if (s[x][y] == 'U')
        res = dfs(x - 1, y);
    if (s[x][y] == 'D')
        res = dfs(x + 1, y);
    f[x][y] = res + 1;
    return f[x][y];
}

inline void solve()
{
    ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (f[i][j])
                continue;
            dfs(i, j);
            if (flag)
            {
                P cir = stk[top];
                int x = f[cir.first][cir.second];
                do
                {
                    f[stk[top].first][stk[top].second] = x;
                    vis[stk[top].first][stk[top].second] = false;
                    --top;
                } while (cir != stk[top]);
            }
            while (top)
            {
                vis[stk[top].first][stk[top].second] = false;
                --top;
            }
            if (ans < f[i][j])
            {
                ans = f[i][j];
                ans_x = i, ans_y = j;
            }
            flag = false;
        }
    }
    printf("%d %d %d\n", ans_x, ans_y, ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}