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

int n, m, a[110], b[110], c[210];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i <= n + m; ++i)
        scanf("%d", c + i);
    for (int i = m; i >= 0; --i)
    {
        b[i] = c[i + n] / a[n];
        for (int j = 0; j <= n; ++j)
            c[i + j] -= b[i] * a[j];
    }
    for (int i = 0; i <= m; ++i)
        printf("%d%c", b[i], " \n"[i == m]);
    return 0;
}