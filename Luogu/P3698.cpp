#include <algorithm>
#include <cstdio>

int n, m, head[110], to[210], next[210], tot;
int len, cur;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int pre)
{
    len = std::max(len, cur);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        ++cur;
        dfs(v, u);
        --cur; 
    }
}   

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    dfs(0, 0);
    if (len >= m)
        printf("%d\n", m + 1);
    else
        printf("%d\n", std::min(n, len + 1 + (m - len) / 2));
}