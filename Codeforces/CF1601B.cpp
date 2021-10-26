/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using std::pair;

typedef pair<int, int> P;

const int maxn = 3e5 + 10;
int n, a[maxn], b[maxn], pre[maxn][2], ans = -1;
bool vis[maxn];
std::queue<P> q;
std::vector<int> path;

template<typename T>
inline void input(T &x)
{
    x = 0;
    char ch = getchar();
    bool f = false;
    while (!isdigit(ch))
    {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x * 10) + (ch ^ 48);
        ch = getchar();
    }
    x = f ? -x : x;
}

void bfs()
{
    q.push(P(n, 0));
    vis[n] = true;
    int bound = n;
    P cur;
    while (ans == -1 && !q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = a[cur.first], pos; i > 0; --i)
        {
            pos = cur.first - i;
            if (pos <= 0)
            {
                pre[0][0] = cur.first;
                ans = cur.second + 1;
                break;
            }
            if (pos >= bound)
                break;
            if (!vis[pos + b[pos]])
            {
                pre[pos + b[pos]][0] = pos;
                pre[pos + b[pos]][1] = cur.first;
                vis[pos + b[pos]] = true;
                q.push(P(pos + b[pos], cur.second + 1));
            }
        }
        bound = std::min(bound, cur.first - a[cur.first]);
    }
}

int main()
{
    input(n);
    for (int i = 1; i <= n; ++i)
        input(a[i]);
    for (int i = 1; i <= n; ++i)
        input(b[i]);
    bfs();
    printf("%d\n", ans);
    if (ans == -1)
        return 0;
    int cur = pre[0][0];
    path.push_back(0);
    while (cur != n)
    {
        path.push_back(pre[cur][0]);
        cur = pre[cur][1];
    }
    for (auto it = path.rbegin(); it != path.rend(); ++it)
        printf("%d ", *it);
    return 0;
}