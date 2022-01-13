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

const int maxn = 5e5 + 10;
int n, k, p[maxn];
std::set<int> s;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", p + i);
        s.insert(p[i]);
    }
    printf("%d\n", *s.begin());
    int cur = *s.begin();
    for (int i = k + 1; i <= n; ++i)
    {
        scanf("%d", p + i);
        s.insert(p[i]);
        if (p[i] > cur)
            cur = *s.upper_bound(cur);
        printf("%d\n", cur);
    }
    return 0;
}