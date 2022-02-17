/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
char s[maxn];
int sum[maxn], pos[maxn << 1][2];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 0; i <= 2 * n; ++i)
        pos[i][0] = n;
    pos[n][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + (s[i] == 'G' ? 1 : -1);
        pos[sum[i] + n][0] = std::min(pos[sum[i] + n][0], i);
        pos[sum[i] + n][1] = std::max(pos[sum[i] + n][1], i);
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; ++i)
        ans = std::max(ans, pos[i][1] - pos[i][0]);
    printf("%d\n", ans);
    return 0;
}