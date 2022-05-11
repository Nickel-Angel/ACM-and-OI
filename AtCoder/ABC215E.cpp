/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int n, f[1010][(1 << 10) + 10][10];
char s[1010];

int main()
{
    scanf("%d%s", &n, s + 1);
    for (int i = 1, id; i <= n; ++i)
    {
        id = s[i] - 'A';
        for (int S = 0; S < (1 << 10); ++S)
        {
            for (int j = 0; j < 10; ++j)
            {
                f[i][S][j] = f[i - 1][S][j];
                if (j == id)
                    f[i][S][j] = (f[i][S][j] + f[i - 1][S][j]) % p;
            }
        }
        for (int S = 0; S < (1 << 10); ++S)
        {
            if ((S >> id) & 1)
                continue;
            for (int j = 0; j < 10; ++j)
                f[i][S | (1 << id)][id] = (f[i][S | (1 << id)][id] + f[i - 1][S][j]) % p;
        }
        f[i][1 << id][id] = (f[i][1 << id][id] + 1) % p;
    }
    int ans = 0;
    for (int S = 0; S < (1 << 10); ++S)
    {
        for (int j = 0; j < 10; ++j)
            ans = (ans + f[n][S][j]) % p;
    }
    printf("%d\n", ans);
    return 0;
}