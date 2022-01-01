/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long ll;

using std::min;
using std::max;
using std::sort;
using std::swap;

const int maxn = 5e5 + 10;

char s[maxn], t[maxn];
int sum[maxn];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    sum[0] = s[0] - '0';
    for (int i = 1; i < n; ++i)
    {
        sum[i] = sum[i - 1] + s[i] - '0';
    }
    ll bonus = 0;
    for (int i = 0; i < n; ++i)
    {
        t[i] = '0' + (sum[n - 1 - i] + bonus) % 10;
        bonus = (sum[n - 1 - i] + bonus) / 10;
    }
    if (bonus)
    {
        t[n] = '0' + bonus;
        ++n;
    }
    std::reverse(t, t + n);
    printf("%s", t);
    return 0;
}