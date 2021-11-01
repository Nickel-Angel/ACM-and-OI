/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;

char s[2010], t[2010];
int f[2010][2010];

int main()
{
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n; ++i)
        f[i][0] = i;
    for (int i = 1; i <= m; ++i)
        f[0][i] = i;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + (s[i] != t[j]));
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}