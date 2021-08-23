/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::sort;
using std::vector;

const int maxn = 1e5 + 10;
int n, q, head[maxn], to[maxn << 1], next[maxn << 1], tot = 0, ans;
int size[maxn], par[maxn], depth[maxn], son[maxn], city[maxn], tag[maxn]; 
int top[maxn], dfn[maxn], dfs_t = 0;
vector<int> e[maxn];

class stack
{
  private:
    int s[maxn], cnt;

  public:
    inline void init()
    {
        cnt = 0;
    }

    inline bool empty()
    {
        return cnt == 0;
    }

    inline int size()
    {
        return cnt;
    }

    inline void push(int x)
    {
        s[++cnt] = x;
    }

    inline void pop()
    {
        if (cnt > 0)
            --cnt;
    }

    inline int top()
    {
        return s[cnt];
    }

    inline void print()
    {
        for (int i = 1; i <= cnt; ++i)
            printf("%d%c", s[i], " \n"[i == cnt]);
    }

    inline int& operator [] (int i)
    {
        return i < 0 ? s[cnt + i + 1] : s[i];
    }
}s;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u, int pre)
{
    par[u] = pre, depth[u] = depth[pre] + 1, size[u] = 1;
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre) 
            continue;
        dfs_son(v, u);
        size[u] += size[v];
        if (size[son[u]] < size[v])
            son[u] = v;
    }
}

void dfs_top(int u, int anc)
{
    top[u] = anc;
    dfn[u] = ++dfs_t;
    if (son[u])
        dfs_top(son[u], anc);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == par[u] || v == son[u]) 
            continue;
        dfs_top(v, v);
    }
}

inline int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]]) std::swap(x, y);
        x = par[top[x]];
    }
    return depth[x] < depth[y] ? x : y;
}

inline void insert(int u)
{
    if (s.empty())
    {
        s.push(u);
        return;
    }
    int anc = lca(s.top(), u);
    while (s.size() > 1 && depth[anc] < depth[s[-2]])
    {
        e[s[-2]].push_back(s.top());
        s.pop();
    }
    if (depth[anc] < depth[s.top()])
    {
        e[anc].push_back(s.top());
        s.pop();
    }
    if (s.empty() || s.top() != anc)
        s.push(anc);
    s.push(u);
}

void dfs_solve(int u)
{
    if (tag[u])
    {
        for (auto v : e[u])
        {
            dfs_solve(v);
            if (tag[v])
            {
                ++ans;
                tag[v] = 0;
            }
        }
    }
    else
    {
        for (auto v : e[u])
        {
            dfs_solve(v);
            tag[u] += tag[v];
            tag[v] = 0;
        }
        if (tag[u] > 1)
        {
            ++ans;
            tag[u] = 0;
        }
    }
    e[u].clear();
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs_son(1, 0), dfs_top(1, 1);
    scanf("%d", &q);
    int m;
    bool skip;
    while (q--)
    {
        skip = false, ans = 0;
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", city + i);
            tag[city[i]] = 1;
        }
        for (int i = 1; i <= m; ++i)
        {
            if (tag[par[city[i]]])
            {
                puts("-1");
                skip = true;
                break;
            }
        }
        if (skip)
        {
            for (int i = 1; i <= m; ++i)
                tag[city[i]] = 0;
            continue;
        }
        sort(city + 1, city + m + 1, [](int x, int y){return dfn[x] < dfn[y];});
        s.init();
        if (city[1] != 1)
            s.push(1);
        for (int i = 1; i <= m; ++i)
            insert(city[i]);
        while (s.size() > 1)
        {
            e[s[-2]].push_back(s.top());
            s.pop();
        }
        while (!s.empty())
            s.pop();
        dfs_solve(1);
        tag[1] = 0;
        printf("%d\n", ans);
    }
}