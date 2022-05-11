/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

const int maxn = 1e6 + 10;
int n;
long long x, a[70];
std::map<long long, long long> f;

long long dfs(long long x, int cur)
{
    if (x == 0)
        return 0;
    if (f.count(x))
        return f[x];
    if (cur == n)
        return x / a[cur];
    long long res = dfs(x / a[cur + 1] * a[cur + 1], cur + 1) + x % a[cur + 1] / a[cur];
    if (x % a[cur + 1])
        res = std::min(res, dfs((x + a[cur + 1] - 1) / a[cur + 1] * a[cur + 1], cur + 1) + (a[cur + 1] - x % a[cur + 1]) / a[cur]); 
    f[x] = res;
    return res;
}

int main()
{
    scanf("%d%lld", &n, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);
    printf("%lld\n", dfs(x, 1));
    return 0;
}