/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int p = 998244353;
int n, m, f[1010][12][12][12];

int main()
{
    scanf("%d%d", &n, &m);
    f[0][m + 1][m + 1][m + 1] = 1;
    for (int i = 0; i < n; ++i)
    {   
        for (int j = 1; j <= m + 1; ++j)
        {
            for (int k = j; k <= m + 1; ++k)
            {
                for (int l = k; l <= m + 1; ++l)
                {
                    for (int q = 1; q <= m; ++q)
                    {
                        if (q <= j)
                            f[i + 1][q][k][l] = (f[i + 1][q][k][l] + f[i][j][k][l]) % p;
                        else if (q <= k)
                            f[i + 1][j][q][l] = (f[i + 1][j][q][l] + f[i][j][k][l]) % p;
                        else if (q <= l)
                            f[i + 1][j][k][q] = (f[i + 1][j][k][q] + f[i][j][k][l]) % p;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i + 1; j <= m; ++j)
        {
            for (int k = j + 1; k <= m; ++k)
            {
                ans = (ans + f[n][i][j][k]) % p; 
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}