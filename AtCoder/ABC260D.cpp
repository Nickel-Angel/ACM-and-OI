/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;
typedef pair<int, int> P;

const int maxn = 2e5 + 10;
int k, n, next[maxn], ans[maxn];
std::set<P> s;

int main()
{
    scanf("%d%d", &n, &k);
    memset(ans, -1, sizeof(ans));
    for (int i = 1, x, p, tot; i <= n; ++i)
    {
        scanf("%d", &x);
        auto it = s.lower_bound(P(x, 0));
        if (it == s.end())
        {
            if (k == 1)
            {
                ans[x] = i;
                continue;
            }
            s.insert(P(x, 1));
        }
        else
        {
            p = it -> first, tot = it -> second; 
            s.erase(it);
            if (tot + 1 == k)
            {
                ans[x] = i;
                x = p;
                while (x)
                {
                    ans[x] = i;
                    x = next[x];
                }
                continue;
            }
            s.insert(P(x, tot + 1));
            next[x] = p;
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}