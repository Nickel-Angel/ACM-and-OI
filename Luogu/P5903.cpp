/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int maxn = 5e5 + 10;
int n, q, root; 
int par[maxn][16], depth[maxn], max_depth[maxn], son[maxn], top[maxn];
int head[maxn], to[maxn], next[maxn], tot = 0;
int log_2[maxn], bound;
unsigned int s;
std::vector<int> up[maxn], down[maxn];

inline unsigned int get(unsigned int x) 
{
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

void dfs_son(int u, int cur_depth)
{
    depth[u] = cur_depth;
    max_depth[u] = cur_depth;
    for (int i = 1; i <= bound; ++i)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        dfs_son(v, cur_depth + 1);
        if (max_depth[u] < max_depth[v])
        {
            max_depth[u] = max_depth[v];
            son[u] = v;
        }
    }
}

void dfs_top(int u, int anc)
{
    top[u] = anc;
    if (u == anc)
    {
        for (int i = 0, v = u; i <= max_depth[u] - depth[u]; ++i)
        {
            up[u].push_back(v);
            v = par[v][0];
        }
        for (int i = 0, v = u; i <= max_depth[u] - depth[u]; ++i)
        {
            down[u].push_back(v);
            v = son[v];
        }
    }
    if (son[u]) dfs_top(son[u], anc);
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == son[u]) continue;
        dfs_top(v, v);
    }
}

inline int query(int u, int k)
{
    if (!k) return u;
    int anc = par[u][log_2[k]];
    k -= 1 << log_2[k], k -= depth[anc] - depth[top[anc]];
    return k > 0 ? up[top[anc]][k] : down[top[anc]][-k];
}

int main()
{
    scanf("%d%d%u", &n, &q, &s);
    log_2[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        log_2[i] = log_2[i >> 1] + 1;
        scanf("%d", par[i]);
        if (!par[i][0])
        {
            root = i;
            continue;
        }
        add_edge(par[i][0], i);
    }
    log_2[0] = 0, bound = log_2[n];
    dfs_son(root, 1), dfs_top(root, root);
    int last_ans = 0;
    long long ans = 0;
    for (int i = 1, u, k; i <= q; ++i)
    {
        u = ((get(s) ^ last_ans) % n) + 1;
        k = (get(s) ^ last_ans) % depth[u];
        last_ans = query(u, k);
        ans ^= 1ll * i * last_ans;
    }
    printf("%lld\n", ans);
    return 0;
}