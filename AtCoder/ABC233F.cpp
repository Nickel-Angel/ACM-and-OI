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
#include <set>
#include <map>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::queue;
using std::pair;
using std::map;

typedef pair<int, int> P;

int n, m, pos[1010], a[1010];
vector<P> e[1010];
vector<int> pre, next, path, ans;

inline void find_path(int start, int key)
{
    queue<int> q;
    q.push(start), pre[start] = start;
    int u;
    while (!q.empty())
    {
        u = q.front();
        next[pre[u]] = u;
        if (u == key)
            break;
        q.pop();
        for (auto [v, w] : e[u])
        {
            if (pre[v])
                continue;
            path[v] = w, pre[v] = u;
            //printf("%d %d %d\n", u, v, w);
            q.push(v);
        }
    }
    next[key] = key;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    scanf("%d", &m);
    for (int i = 1, x, y; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        e[x].push_back(P(y, i)), e[y].push_back(P(x, i));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i] == i)
            continue;
        pre = vector<int>(n + 1, 0);
        next = vector<int>(n + 1, 0);
        path = vector<int>(n + 1, 0);
        vector<int> res;
        find_path(pos[i], i);
        if (!pre[i])
        {
            puts("-1");
            return 0;
        }
        int u = pos[i];
        while (u != i)
        {
            u = next[u];
            ans.push_back(path[u]);
        }
        u = pre[u];
        while (u != pos[i])
        {
            ans.push_back(path[u]);
            u = pre[u];
        }
        pos[a[i]] = pos[i], a[pos[i]] = a[i];
        pos[i] = i, a[i] = i;
    }
    printf("%zu\n", ans.size());
    for (auto c : ans)
        printf("%d ", c);
    return 0;
}