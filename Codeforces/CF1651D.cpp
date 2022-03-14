/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;
typedef pair<int, int> P;

const int maxn = 2e5 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, X[maxn], Y[maxn];
P sel[maxn];
bool lock[maxn];
std::map<P, int> id;
std::queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", X + i, Y + i);
        id[P(X[i], Y[i])] = i;
    }
    for (int i = 1, nx, ny; i <= n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            nx = X[i] + dx[j], ny = Y[i] + dy[j];
            if (!id.count(P(nx, ny)))
            {
                q.push(i);
                sel[i] = P(nx, ny);
                lock[i] = true;
                break;
            }
        }
    }
    int cur, x, y, nx, ny, j;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        x = X[cur], y = Y[cur];
        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i], ny = y + dy[i];
            if (!id.count(P(nx, ny)))
                continue;
            j = id[P(nx, ny)];
            if (lock[j])
                continue;
            sel[j] = sel[cur];
            lock[j] = true;
            q.push(j);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", sel[i].first, sel[i].second);
    return 0;
}