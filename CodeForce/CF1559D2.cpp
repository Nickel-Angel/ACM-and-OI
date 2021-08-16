/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, int> P;

const int maxn = 1e5 + 10;

int n, m1, m2;
std::vector<P> ans;
std::queue<int> q1, q2;

class Union_Find_Set
{
  private:
    int fa[maxn], rank[maxn], _bound;

    int find(int x)
    {
        return x = ((x == fa[x]) ? x : find(fa[x])); 
    }

  public:
    inline void init(int bound)
    {
        _bound = bound;
        for (int i = 1; i <= _bound; ++i)
        {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    inline bool unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (rank[fx] > rank[fy]) std::swap(fx, fy);
        fa[fx] = fy;
        if (rank[fx] == rank[fy])
            ++rank[fy];
        return true;
    }

    inline bool judge(int x, int y)
    {
        return find(x) == find(y);
    }
}S, T;

inline bool q1_inner(int x)
{
    return S.judge(1, x) && !T.judge(1, x);
}

inline bool q2_inner(int x)
{
    return T.judge(1, x) && !S.judge(1, x);
}

int main()
{
    scanf("%d%d%d", &n, &m1, &m2);
    S.init(n), T.init(n);
    for (int i = 1, u, v; i <= m1; ++i)
    {
        scanf("%d%d", &u, &v);
        S.unite(u, v);
    }
    for (int i = 1, u, v; i <= m2; ++i)
    {
        scanf("%d%d", &u, &v);
        T.unite(u, v);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (S.judge(1, i) || T.judge(1, i)) continue;
        S.unite(1, i), T.unite(1, i);
        ans.push_back(P(1, i));
    }
    for (int i = 2; i <= n; ++i)
    {
        if (q1_inner(i))
            q1.push(i);
        if (q2_inner(i))
            q2.push(i);
    }
    while (!q1.empty() && !q2.empty())
    {
        while (!q1.empty() && !q1_inner(q1.front()))
            q1.pop();
        while (!q2.empty() && !q2_inner(q2.front()))
            q2.pop();
        if (q1.empty() || q2.empty()) 
            break;
        S.unite(q1.front(), q2.front());
        T.unite(q1.front(), q2.front());
        ans.push_back(P(q1.front(), q2.front()));
    }
    printf("%u\n", ans.size());
    for (auto c : ans)
        printf("%d %d\n", c.first, c.second);
    return 0;
}