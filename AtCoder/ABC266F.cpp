/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

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
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, m, head[maxn], to[maxn << 1], next[maxn << 1], in[maxn], tot;
int color[maxn];
std::queue<int> q;
vector<int> ring;

inline void add_edge(int u, int v)
{
    ++in[v];
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

inline void get_ring(int S)
{
    int u = S, c, v;
    do
    {
        color[u] = u;
        in[u] = 1;
        ring.push_back(u);
        for (c = head[u]; c; c = next[c])
        {
            v = to[c];
            if (in[v] > 1)
            {
                u = v;
                break;
            }
        }
    } while (c);
    
}

void dfs(int u, int pre)
{
    color[u] = color[pre];
    for (int c = head[u], v; c; c = next[c])
    {
        v = to[c];
        if (v == pre)
            continue;
        dfs(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i <= n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 1)
            q.push(i);
    }
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (in[v] > 1)
            {
                --in[v];
                if (in[v] == 1)
                    q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] > 1)
        {
            u = i;
            break;
        }
    }
    get_ring(u);
    for (int u : ring)
    {
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (!color[v])
            {
                //printf("%d\n", v);
                dfs(v, u);
            }
        }
    }
    scanf("%d", &m);
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        puts(color[x] == color[y] ? "Yes" : "No");
    }
    return 0;
}