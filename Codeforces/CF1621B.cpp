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

int n;
ll ansl, ansr, ans;

inline void solve()
{
    scanf("%d", &n);
    int L, R;
    scanf("%d%d%lld", &L, &R, &ans);
    ansl = ansr = ans;
    printf("%lld\n", ans);
    bool flag = true;
    for (int i = 1, l, r, x; i < n; ++i)
    {
        scanf("%d%d%d", &l, &r, &x);
        if (l < L)
        {
            ans = 1e14;
            ansl = x;
            flag = false;
            L = l;
        }
        if (r > R)
        {
            ans = 1e14;
            ansr = x;
            flag = false;  
            R = r;
        }
        if (l == L && r == R)
        {
            ans = min(ans, (ll)x);
            flag = true;
        }
        if (l == L)
            ansl = min(ansl, (ll)x);
        if (r == R)
            ansr = min(ansr, (ll)x);
        printf("%lld\n", flag ? min(ans, ansl + ansr) : ansl + ansr);
    }    
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}