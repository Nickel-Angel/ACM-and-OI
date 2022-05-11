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

int n, m, r, c;

inline int check(int x, int y)
{
    return x <= n && y <= m && x > 0 && y > 0 ? 1 : 0;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    printf("%d\n", check(r + 1, c) + check(r, c + 1) + check(r - 1, c) + check(r, c - 1));
    return 0;
}