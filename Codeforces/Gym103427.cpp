/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

int a, b, num[5], dis[10010];
std::vector<int> A, B;

void bfs()
{
    std::queue<int> q;
    q.push(0);
    dis[0] = 0;
    int x, cur;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        A.clear();
        cur = x;
        while (cur)
        {
            A.push_back(cur % 10);
            cur /= 10;
        }
        while (A.size() < 4)
            A.push_back(0);
        std::reverse(A.begin(), A.end());
        for (int i = 1, y; i <= 4; ++i)
        {
            for (int j = 0; j <= 4 - i; ++j)
            {
                y = 0, B = A;
                for (int k = j; k < j + i; ++k)
                    B[k] = (B[k] + 1) % 10;
                for (int k = 0; k < 4; ++k)
                    y = y * 10 + B[k];
                if (dis[y] == 0 && y != 0)
                {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
                y = 0, B = A;
                for (int k = j; k < j + i; ++k)
                    B[k] = (B[k] + 9) % 10;
                for (int k = 0; k < 4; ++k)
                    y = y * 10 + B[k];
                
                if (dis[y] == 0 && y != 0)
                {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
    }
}

inline void solve()
{
    A.clear(), B.clear();
    scanf("%d%d", &a, &b);
    while (a)
    {
        A.push_back(a % 10);
        a /= 10;
    }
    while (A.size() < 4)
        A.push_back(0);
    while (b)
    {
        B.push_back(b % 10);
        b /= 10;
    }
    while (B.size() < 4)
        B.push_back(0);
    int ans = 0x3f3f3f3f, x = 0;
    for (int j = 0; j < 4; ++j)
        x = x * 10 + (A[j] >= B[j] ? A[j] - B[j] : 10 - B[j] + A[j]);
    ans = std::min(ans, dis[x]);
    printf("%d\n", ans);
}

int main()
{
    bfs();
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}