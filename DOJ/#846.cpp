/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

const int maxn = 1e5 + 10;
int n, a[maxn], id[maxn];
std::set<int> s;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return a[x] > a[y];});
    s.insert(0), s.insert(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        s.insert(id[i]);
        auto it = s.lower_bound(id[i]);
        auto l = it, r = it;
        --l, ++r;
        auto ll = l, rr = r;
        --ll, ++rr;
        if (*l > 0)
            ans += 1ll * a[id[i]] * (*l - *ll) * (*r - id[i]);
        if (*r <= n)
            ans += 1ll * a[id[i]] * (*rr - *r) * (id[i] - *l);
    }
    printf("%lld\n", ans);
    return 0;
}