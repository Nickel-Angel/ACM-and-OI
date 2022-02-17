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
int n, a[maxn], log_2[maxn], st[maxn][21];

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

inline int query(int l, int r)
{
    int k = log_2[r - l + 1];
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    scanf("%d", &n);
    log_2[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", st[i]);
        log_2[i] = log_2[i >> 1] + 1;
    }
    log_2[0] = 0;
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l, r, mid, last = 0, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        l = last + 1, r = i;
        while (l < r)
        {
            mid = (l + r + 1) >> 1;
            if (query(mid, i) > i - mid + 1)
                r = mid - 1;
            else
                l = mid;
        }
        if (i - l + 1 == query(l, i))
        {
            ++ans;
            last = i;
        }
        printf("%d ", ans);
    }
    return 0;
}