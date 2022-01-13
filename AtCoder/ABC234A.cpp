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

int n;

inline ll f(ll x)
{
    return x * x + 2 * x + 3;
}

int main()
{
    scanf("%d", &n);
    printf("%lld\n", f(f(f(n) + n) + f(f(n))));
    return 0;
}