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
const char trans[3][3] = {"BC", "CA", "AB"};
char s[maxn];
int q;

char dfs(ll t, ll pos)
{
    if (!pos)
        return 'A' + (s[0] - 'A' + t % 3) % 3;
    if (!t)
        return s[pos];
    return trans[dfs(t - 1, pos >> 1) - 'A'][pos & 1];
}

int main()
{
    scanf("%s%d", s, &q);
    ll t, k, pos;
    char ans;
    while (q--)
    {
        scanf("%lld%lld", &t, &k);
        --k;
        printf("%c\n", dfs(t, k));
    }
    return 0;
}