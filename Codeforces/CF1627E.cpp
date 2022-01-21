/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

using std::pair;
using std::vector;

typedef long long ll;
typedef pair<ll, int> P;

const int maxn = 2e5 + 10;
int n, m, k, cnt;
ll dis[maxn];
std::map<P, int> id;
std::map<int, vector<int>> f;
vector<P> e[maxn];

inline void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    std::vector<ll> x(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &x[i]);
    cnt = 0, id.clear(), f.clear();
    id[P(1, 1)] = ++cnt, f[1].push_back(1);
    id[P(n, m)] = ++cnt, f[n].push_back(m);
    for (int i = 1, a, b, c, d, h; i <= k; ++i)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
        if (!id.count(P(a, b)))
        {
            id[P(a, b)] = ++cnt;
            f[a].push_back(b);
        }
        if (!id.count(P(c, d)))
        {
            id[P(c, d)] = ++cnt;
            f[c].push_back(d);
        }
        e[id[P(a, b)]].push_back(P(id[P(c, d)], h));
    }
    for (int i = 1; i <= cnt; ++i)
        dis[i] = 1e16;
    dis[1] = 0;
    int pre, u;
    for (auto [a, vec] : f)
    {
        std::sort(vec.begin(), vec.end());
        for (unsigned i = 1; i < vec.size(); ++i)
        {
            pre = id[P(a, vec[i - 1])], u = id[P(a, vec[i])];
            dis[u] = std::min(dis[u], dis[pre] + x[a] * (vec[i] - vec[i - 1]));
        }
        for (unsigned i = vec.size() - 1; i > 0; --i)
        {
            pre = id[P(a, vec[i])], u = id[P(a, vec[i - 1])];
            dis[u] = std::min(dis[u], dis[pre] + x[a] * (vec[i] - vec[i - 1]));
        }
        for (int i : vec)
        {
            u = id[P(a, i)];
            if (dis[u] >= 1e16)
                continue;
            for (auto [v, w] : e[u])
            {
                dis[v] = std::min(dis[v], dis[u] - w);
            }
        }
    }
    if (dis[2] >= 1e16)
        puts("NO ESCAPE");
    else
        printf("%lld\n", dis[2]);
    for (int i = 1; i <= cnt; ++i)
        e[i].clear();
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}