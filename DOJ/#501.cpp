/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::max;

const int maxn = 1e5 + 10;
int n, h[maxn], fl[maxn], fr[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", h + i);
    fl[1] = 1;
    for (int i = 2; i <= n; ++i)
        fl[i] = min(fl[i - 1] + 1, h[i]);
    fr[n] = 1;
    for (int i = n - 1; i > 0; --i)
        fr[i] = min(fr[i + 1] + 1, h[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, min(fl[i], fr[i]));
    printf("%d\n", ans);
    return 0;
}