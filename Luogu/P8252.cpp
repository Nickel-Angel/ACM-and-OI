/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using std::vector;
using std::map;

const int maxn = 1e6 + 10;
int n, id[maxn], k[maxn], last[maxn << 1], cnt[maxn];
vector<int> v[maxn];

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", k + i);
        v[i].clear();
        for (int j = 0, x; j < k[i]; ++j)
        {
            scanf("%d", &x);
            v[i].push_back(x);
        }
        id[i] = i;
    }
    std::sort(id + 1, id + n + 1, [&](int x, int y){return k[x] < k[y];});
    memset(cnt, 0, sizeof(cnt));
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < k[id[i]]; ++j)
        {
            if (last[v[id[i]][j]])
                ++cnt[last[v[id[i]][j]]];
        }
        for (int j = 0; j < k[id[i]]; ++j)
        {
            if (cnt[last[v[id[i]][j]]] && cnt[last[v[id[i]][j]]] < k[last[v[id[i]][j]]])
            {
                puts("YES");
                printf("%d %d\n", last[v[id[i]][j]], id[i]);
                return;
            }
            cnt[last[v[id[i]][j]]] = 0;
            last[v[id[i]][j]] = id[i];
        }
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}