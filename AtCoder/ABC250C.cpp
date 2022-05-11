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

const int maxn = 2e5 + 10;
int n, q, a[maxn], pos[maxn];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
        pos[i] = i;
    }
    for (int i = 1, x, pre; i <= q; ++i)
    {
        scanf("%d", &x);
        pre = pos[x];
        if (pre < n)
        {
            swap(pos[x], pos[a[pre + 1]]);
            swap(a[pre], a[pre + 1]);
        }
        else
        {
            swap(pos[x], pos[a[pre - 1]]);
            swap(a[pre], a[pre - 1]);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}