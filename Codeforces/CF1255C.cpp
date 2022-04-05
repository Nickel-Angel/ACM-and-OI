/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, q[maxn][3];
bool vis[maxn], lock[maxn];
vector<int> pos[maxn];

inline int find_q(int x, int y)
{
    for (int i : pos[x])
    {
        for (int j : pos[y])
        {
            if (i == j && !lock[i])
                return i;
        }
    }
    return -1;
}

inline int find_p(int x)
{
    for (int i = 0; i < 3; ++i)
    {
        if (!vis[q[x][i]])
            return q[x][i];
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 2; ++i)
    {
        scanf("%d%d%d", q[i], q[i] + 1, q[i] + 2);
        pos[q[i][0]].push_back(i);
        pos[q[i][1]].push_back(i);
        pos[q[i][2]].push_back(i);
    }
    int key = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (pos[i].size() == 1)
        {
            key = i;
            break;
        }
    }
    int cnt = 3, cur = pos[key].front();
    sort(q[cur], q[cur] + 3, [&](int x, int y){return pos[x].size() < pos[y].size();});
    printf("%d %d %d ", q[cur][0], q[cur][1], q[cur][2]);
    vis[q[cur][0]] = true, vis[q[cur][1]] = true, vis[q[cur][2]] = true;
    lock[cur] = true;
    int x, pre = q[cur][2];
    cur = find_q(q[cur][1], q[cur][2]);
    while (cnt < n)
    {
        x = find_p(cur);
        lock[cur] = true;
        printf("%d ", x);
        ++cnt;
        vis[x] = true;
        cur = find_q(x, pre);
        pre = x;
    }
    return 0;
}