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

const int maxn = 1e6 + 10;
const int p = 998244353;
int n, f[maxn][10];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < 10; ++i)
        f[1][i] = 1;
    for (int i = 2; i <= n; ++i)
    {
        f[i][1] = (f[i - 1][1] + f[i - 1][2]) % p;
        for (int j = 2; j < 9; ++j)
        {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % p;
            f[i][j] = (f[i][j] + f[i - 1][j + 1]) % p;
        }
        f[i][9] = (f[i - 1][9] + f[i - 1][8]) % p;
    }
    int ans = 0;
    for (int i = 1; i < 10; ++i)
        ans = (ans + f[n][i]) % p;
    printf("%d\n", ans);
    return 0;
}