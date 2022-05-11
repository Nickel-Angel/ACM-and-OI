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

const int p = 1e9 + 7;
const int maxn = 4e4 + 10;
int n, v[maxn], a[maxn], f[maxn], tot;

inline bool check(int x)
{
    int p = 1, q = 0;
    while (x)
    {
        a[++q] = x % 10;
        x /= 10;
    }
    while (p < q)
    {
        if (a[p] != a[q])
            return false;
        ++p, --q;
    }
    return true;
}

int main()
{
    for (int i = 1; i <= 40000; ++i)
    {
        if (check(i))
            v[++tot] = i;
    }
    f[0] = 1;
    for (int i = 1; i <= tot; ++i)
    {
        for (int j = 1; j <= 40000; ++j)
        {
            if (j >= v[i])
                f[j] = (f[j] + f[j - v[i]]) % p;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}