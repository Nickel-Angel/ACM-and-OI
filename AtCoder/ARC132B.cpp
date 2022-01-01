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

const int maxn = 1e5 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    bool flag = true;
    int pos = 0;
    scanf("%d", a + 1);
    if (a[1] == 1)
        pos = 1;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", a + i);
        if (a[i] == 1)
            pos = i;
        if (a[i] - a[i - 1] == 1)
            flag = false;
    }
    printf("%d\n", min(flag ? n - pos + 1 : n - pos + 3, flag ? pos + 1 : pos - 1));
    return 0;
}