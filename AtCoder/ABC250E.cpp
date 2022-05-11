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

const int maxn = 2e5 + 10;
int n, m, a[maxn], b[maxn], ansA[maxn], ansB[maxn];
std::map<int, int> firA, firB;
std::priority_queue<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (!firA.count(a[i]))
            firA[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        if (!firB.count(b[i]))
            firB[b[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!firB.count(a[i]))
            q.push(n + 1);
        else
            q.push(firB[a[i]]);
        ansA[i] = q.top();
    }
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; ++i)
    {
        if (!firA.count(b[i]))
            q.push(n + 1);
        else
            q.push(firA[b[i]]);
        ansB[i] = q.top();
    }
    scanf("%d", &m);
    int x, y;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        puts(ansA[x] <= y && ansB[y] <= x ? "Yes" : "No");
    }
    return 0;
}