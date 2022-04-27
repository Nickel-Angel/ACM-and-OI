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
 
using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;
 
typedef long long ll;
 
const int maxn = 2e5 + 10;
int n, k, t[maxn], y[maxn];
std::priority_queue<int> q;
 
int main()
{
    scanf("%d%d", &n, &k);
    ll add = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", t + i, y + i);
    t[0] = 1, y[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i] == 2)
            ans += y[i];
        else
            ans = y[i];
    }
    for (int i = n; i >= 0; --i)
    {
        if (t[i] == 2)
        {
            if (y[i] >= 0)
                add += y[i];
            else
            {
                if (k == 0)
                {
                    add += y[i];
                    continue;
                }
                if (q.size() < k)
                    q.push(y[i]);
                else
                {
                    if (q.top() <= y[i])
                        add += y[i];
                    else
                    {
                        add += q.top();
                        q.pop();
                        q.push(y[i]);
                    }
                }
            }
        }
        else
        {
            ans = max(ans, y[i] + add);
            if (k == 0)
                break;
            if (k > 0)
                --k;
            if (q.size() > k)
            {
                add += q.top();
                q.pop();
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}