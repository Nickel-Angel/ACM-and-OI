/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 2e5 + 10;
const int maxm = 5e5 + 10;
int n, m, head[maxn], to[maxm << 1], next[maxm << 1], val[maxm << 1], tot;
int state[maxn], cnt[2];
char s[10];
bool vis[maxn], flag;

inline void add_edge(int u, int v, int w)
{
    to[++tot] = v;
    val[tot] = w;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int cur)
{
    if (flag)
        return;
    vis[u] = true, state[u] = cur, ++cnt[cur];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (vis[v])
        {
            if ((cur ^ val[c]) != state[v])
            {
                flag = true;
                return;
            }
            continue;
        }
        dfs(v, cur ^ val[c]);
    }
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = false;
        head[i] = 0;
    }
    tot = 0, flag = false;
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d%s", &u, &v, s);
        add_edge(u, v, s[0] == 'i'), add_edge(v, u, s[0] == 'i');
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        cnt[0] = 0, cnt[1] = 0;
        dfs(i, 0);
        if (flag)
        {
            puts("-1");
            return;
        }
        ans += std::max(cnt[0], cnt[1]);
    }
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