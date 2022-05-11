/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;
using std::pair;

typedef long long ll;

const int maxn = 1e5 + 10;
int n, m, a[maxn];
bool tag[maxn];
std::set<int> s;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        for (int j = 2; j <= a[i] / j; ++j)
        {
            if (a[i] % j == 0)
            {
                while (a[i] % j == 0)
                    a[i] /= j;
                s.insert(j);
            }
        }
        if (a[i] > 1)
            s.insert(a[i]);
    }
    int cnt = m;
    for (int p : s)
    {
        for (int i = 1; i <= m / p; ++i)
        {
            if (!tag[p * i])
                --cnt;
            tag[p * i] = true;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= m; ++i)
    {
        if (!tag[i])
            printf("%d\n", i);
    }
    return 0;
}