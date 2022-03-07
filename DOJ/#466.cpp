/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

const int maxn = 2e5 + 10;
int n, k, sum[maxn], q[maxn];
std::map<int, int> f;

int main()
{
    scanf("%d%d", &n, &k);
    long long ans = 0;
    int L = 1, R = 1;
    f[0] = 1, q[1] = 0;
    for (int i = 1, x, y; i <= n; ++i)
    {
        scanf("%d", &x);
        sum[i] = (sum[i - 1] + x) % k;
        y = ((sum[i] - i) % k + k) % k;
        q[++R] = y;
        if (R - L + 1 > k)
        {
            --f[q[L]];
            ++L;
        }
        ans += f[y];
        ++f[y];
    }
    printf("%lld\n", ans);
}