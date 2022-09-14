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

const int maxn = 1e5 + 10;
int n, id[maxn], help[maxn], t[maxn], x[maxn], y[maxn], c[maxn];
ll f[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", t + i, x + i, y + i, c + i);
        id[i] = i, help[i] = t[i];
    }
    sort(help + 1, help + n + 1);
    sort(id + 1, id + n + 1, [&](int a, int b){return x[a] == x[b] ? t[a] < t[b] : x[a] < x[b];});
    int cnt = std::unique(help + 1, help + n + 1) - help;
    for (int i = 1; i <= n; ++i)
        t[i] = std::lower_bound(help + 1, help + cnt, t[i]) - help;
    
    return 0;
}