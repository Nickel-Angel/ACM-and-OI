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

const int p = 998244353;
int n, d, a[510], f[510][(1 << 16) - 10];

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        --a[i];
    }
    f[0][(1 << (d + 1)) - 1] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int S = 1, T; S < (1 << (2 * d + 1)); S += 2)
        {
            T = S >> 1;
            for (int j = 0; j <= 2 * d; ++j)
            {
                if (a[i] >= 0 && a[i] != i + j - d)
                    continue;
                if (~T >> j & 1)
                    f[i + 1][T | 1 << j] = (f[i + 1][T | 1 << j] + f[i][S]) % p;
            }
        }
    }
    printf("%d\n", f[n][(1 << (d + 1)) - 1]);
    return 0;
}