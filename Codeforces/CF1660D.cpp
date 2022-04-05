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

const int maxn = 2e5 + 10;
int n, L, R, a[maxn];

inline int calc(vector<int> &v, int cur)
{
    if (v.empty())
        return 0;
    int res = 0, cnt = 0, l = v.size() - 1, r = 0;
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (v[i] < 0)
        {
            l = min(l, i);
            r = max(r, i);
            ++cnt;
        }
        if (v[i] == 2 || v[i] == -2)
            ++res;
    }
    if (cnt & 1)
    {
        int pre = 0, suf = 0;
        for (int i = 0; i < r; ++i)
        {
            if (v[i] == 2 || v[i] == -2)
                ++pre;
        }
        for (int i = (int)v.size() - 1; i > l; --i)
        {
            if (v[i] == 2 || v[i] == -2)
                ++suf;
        }
        if (pre < suf)
        {
            L = cur + l + 1, R = cur + v.size() - 1;
            return suf;
        }
        else
        {
            L = cur, R = cur + r - 1;
            return pre;
        }
    }
    L = cur, R = cur + v.size() - 1;
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    int l = n, r = 0, ans = 0, res;
    vector<int> v;
    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (i <= n)
            scanf("%d", a + i);
        if (a[i] == 0)
        {
            res = calc(v, i - v.size());
            if (res > ans)
            {
                l = L - 1, r = n - R;
                ans = res;
            }
            v.clear();    
        }
        else
            v.push_back(a[i]);
    }
    printf("%d %d\n", l, r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}