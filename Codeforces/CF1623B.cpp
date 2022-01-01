/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
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

struct line
{
    int id, l, r;

    line() {}

    line(int id, int l, int r): id(id), l(l), r(r) {}
    
    bool operator < (const line &rhs) const
    {
        return r - l < rhs.r - rhs.l;
    }
}S[1010];

int n, ch[1010][2], par[1010], cur[1010];
std::priority_queue<line> q;

void dfs(int u)
{
    if (S[u].l == S[u].r)
    {
        printf("%d %d %d\n", S[u].l, S[u].r, S[u].l);
        return;
    }
    if (ch[u][0])
    {
        printf("%d %d %d\n", S[u].l, S[u].r, S[ch[u][0]].r + 1);
        dfs(ch[u][0]);
    }
    if (ch[u][1])
    {
        if (!ch[u][0])
            printf("%d %d %d\n", S[u].l, S[u].r, S[ch[u][1]].l - 1);
        dfs(ch[u][1]);
    }
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1, l, r; i <= n; ++i)
    {
        cur[i] = 0, ch[i][0] = 0, ch[i][1] = 0;
        scanf("%d%d", &l, &r);
        S[i] = line(i, l, r);
        q.push(S[i]);
    }
    cur[q.top().l] = q.top().id, cur[q.top().r] = q.top().id;
    int root = q.top().id;
    q.pop();
    while (!q.empty())
    {
        int l = q.top().l, r = q.top().r, id = q.top().id;
        if (S[cur[l]].l == l)
        {
            ch[cur[l]][0] = id;
            par[id] = cur[l];
        }
        else
        {
            ch[cur[r]][1] = id;
            par[id] = cur[r];
        }   
        cur[l] = id, cur[r] = id;      
        q.pop();
    }
    dfs(root);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}