/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::min;

const int maxn = 1e6 + 10;
int n, l[maxn], r[maxn], f[maxn], q[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", l + i, r + i);
    int L = 1, R = 0, ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (L <= R && l[q[L]] > r[i])
            ++L;
        if (L <= R)
            ans = max(ans, i - f[q[L]] + 1);
        f[i] = L <= R ? f[q[L]] : i;
        while (L <= R && l[q[R]] < l[i])
            --R;
        q[++R] = i;
    }
    printf("%d\n", ans);
    return 0;
}