/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

const int maxn = 2e5 + 10;
int n, a[maxn], l[maxn], r[maxn];
std::map<int, int> pre;

bool dfs(int L, int R)
{
    if (L >= R)
        return true;
    int p = L, q = R;
    while (p <= q)
    {
        if (l[p] < L && R < r[p])
            return dfs(L, p - 1) & dfs(p + 1, R);
        if (l[q] < L && R < r[q])
            return dfs(L, q - 1) & dfs(q + 1, R);
        ++p, --q;
    }
    return false;
}

inline void solve()
{
    pre.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (pre.count(a[i]))
        {
            l[i] = pre[a[i]];
            r[l[i]] = i;
        }
        else
            l[i] = 0;
        r[i] = n + 1;
        pre[a[i]] = i;
    }
    puts(dfs(1, n)? "non-boring" : "boring");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}