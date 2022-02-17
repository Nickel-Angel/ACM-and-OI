/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int m, n, a[maxn], len[maxn];
int head[maxn], to[maxn << 1], next[maxn << 1], tot, cnt;
char ans[maxn];
std::map<int, int> pre;
std::map<int, bool> lock;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, char color)
{
    ans[u] = color;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (ans[v])
            continue;
        dfs(v, color == 'L' ? 'R' : 'L');
    }
}

int main()
{
    scanf("%d", &m);
    for (int j = 1; j <= m; ++j)
    {
        scanf("%d", &n);
        len[j] = n;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            ++cnt;
            if (i & 1)
            {
                add_edge(cnt, cnt + 1);
                add_edge(cnt + 1, cnt);
            }
            if (!lock[a[i]])
            {
                pre[a[i]] = cnt;
                lock[a[i]] = true;
            }
            else
            {
                add_edge(pre[a[i]], cnt), add_edge(cnt, pre[a[i]]);
                lock[a[i]] = false;
            }
        }
    }
    for (auto &[i, b] : lock)
    {
        if (b)
        {
            puts("NO");
            return 0;
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        if (ans[i])
            continue;
        dfs(i, 'L');
    }
    puts("YES");
    for (int i = 1, k = 0; i <= m; ++i)
    {
        for (int j = 1; j <= len[i]; ++j)
        {
            ++k;
            putchar(ans[k]);
        }   
        puts("");
    }
    return 0;
}