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
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 2e5 + 10;
int n, m, a[maxn], b[maxn], c[maxn], d[maxn], help[maxn << 1];
std::multiset<int> s;
vector<int> add[maxn << 1], sub[maxn << 1];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        help[i] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", c + i);
        help[i + n] = c[i];
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", d + i);
    sort(help + 1, help + n + m + 1);
    int cnt = std::unique(help + 1, help + n + m + 1) - help - 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = std::lower_bound(help + 1, help + cnt + 1, a[i]) - help;
        sub[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        c[i] = std::lower_bound(help + 1, help + cnt + 1, c[i]) - help;
        add[c[i]].push_back(d[i]);
    }
    for (int i = cnt; i > 0; --i)
    {
        for (int y : add[i])
            s.insert(y);
        for (int y : sub[i])
        {
            auto it = s.lower_bound(y);
            if (it == s.end())
            {
                puts("No");
                return 0;
            }
            s.erase(it);
        }
    }
    puts("Yes");
    return 0;
}