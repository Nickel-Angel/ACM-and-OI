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

const int maxn = 5e5 + 10;
int n, id[maxn], a[maxn], b[maxn], l[maxn], r[maxn];
std::set<P> s;

inline void solve()
{
    s.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", b + i);
        l[i] = i / (b[i] + 1) + 1;
        r[i] = b[i] == 0 ? n : i / b[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int x, int y){return l[x] == l[y] ? r[x] < r[y] : l[x] < l[y];});
    for (int i = 1, j = 1; i <= n; ++i)
    {
        while (j <= n && l[id[j]] <= i)
        {
            s.insert(P(r[id[j]], id[j]));
            ++j;
        }
        a[s.begin() -> second] = i;
        s.erase(s.begin());
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}