/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>

typedef std::pair<int, int> P;

using std::vector;
using std::min;

int n, m, q;
std::map<P, int> syn;

int bfs()
{
    vector<P> cur, buf;
    cur.push_back(P(1, 1));
    for (int i = 0; !cur.empty(); ++i)
    {
        std::sort(cur.rbegin(), cur.rend());
        buf.clear();
        for (auto [x, y] : cur)
        {
            if (x == n && y == m)
                return i;
            if (buf.empty() || buf.back().second < y)
                buf.push_back(P(x, y));
        }
        cur.clear();
        for (auto [x, y] : buf)
        {
            cur.push_back(P(min(n, x + y + syn[P(x, y)]), y));
            cur.push_back(P(x, min(m, x + y + syn[P(x, y)])));
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        syn[P(x, y)] = 1;
    }
    printf("%d\n", bfs());
    return 0;
}