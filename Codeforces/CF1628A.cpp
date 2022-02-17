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

const int maxn = 2e5 + 10;
int n, a[maxn];
std::set<int> s[maxn];
std::vector<int> ans;

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        s[a[i]].insert(i);
    }
    int pos = 1, pre = 1;
    ans.clear();
    while (pos <= n)
    {
        for (int i = 0; i <= n; ++i)
        {
            if (s[i].lower_bound(pos) == s[i].end())
            {
                pos = pre + 1;
                pre = pos;
                ans.push_back(i);
                break;
            }
            else
                pre = max(pre, *(s[i].lower_bound(pos)));
        }
        //printf("%d %d\n", pre, pos);
    }
    printf("%zu\n", ans.size());
    for (int i : ans)
        printf("%d ", i);
    puts("");
    for (int i = 0; i <= n; ++i)
        s[i].clear();
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}