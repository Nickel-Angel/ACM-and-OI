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

int n, m, a[110], b[110];

int main()
{
    scanf("%d%d", &n, &m);
    int ma = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ma = std::max(ma, a[i]);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", b + i);
    sort(b + 1, b + m + 1);
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (i > b[j])
            ++j;
        if (j > m)
            break;
        if (ma == a[i] && b[j] == i)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}