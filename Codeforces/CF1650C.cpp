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
int n, m, id[maxn], x[maxn], w[maxn];
vector<int> v;

inline void solve()
{
    v.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", x + i, w + i);
        id[i] = i;
    }
    sort(id + 1, id + m + 1, [&](int a, int b){return w[a] < w[b];});
    ll ans = 0;
    for (int i = 1; i <= 2 * n; ++i)
    {
        ans += w[id[i]];
        v.push_back(id[i]);
    }
    sort(v.begin(), v.end(), [&](int a, int b){return x[a] < x[b];});
    printf("%lld\n", ans);
    for (unsigned i = 0, j = v.size() - 1; i < j; ++i, --j)
        printf("%d %d\n", v[i], v[j]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}