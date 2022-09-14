/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;
typedef pair<ll, int> P;

const int maxn = 2e5 + 10;
int n, m, a[maxn], head[maxn], to[maxn << 1], next[maxn << 1], tot;
bool del[maxn];
ll sum[maxn];
std::set<P> s;

inline void add_edge(int u, int v)
{
    to[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int c = head[i], v; c; c = next[c])
        {
            v = to[c];
            sum[i] += a[v];
        }
        s.emplace(sum[i], i);
    }
    ll ans = s.begin() -> first;
    int u;
    for (int i = 1; i < n; ++i)
    {
        ans = max(ans, s.begin() -> first);
        u = s.begin() -> second;
        s.erase(s.begin());
        del[u] = true;
        for (int c = head[u], v; c; c = next[c])
        {
            v = to[c];
            if (del[v])
                continue;
            auto it = s.find(P(sum[v], v));
            if (it != s.end())
                s.erase(it);
            sum[v] -= a[u];
            s.emplace(sum[v], v);
        }
    }
    printf("%lld\n", ans);
    return 0;
}