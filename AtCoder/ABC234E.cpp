/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cassert>
#include <vector>
#include <set>

using std::max;
using std::min;
using std::pair;
using std::sort;
using std::swap;
using std::vector;

typedef long long ll;

ll n;
vector<int> v;

int main()
{
    scanf("%lld", &n);
    std::set<ll> s;
    for (int i = 1; i < 10; ++i)
    {
        for (int d = -9; d < 9; ++d)
        {
            ll x = i, cur = 0;
            for (int j = 0; j < 18; ++j)
            {
                cur = cur * 10 + x;
                s.insert(cur);
                x += d;
                if (x < 0 || x > 9)
                    break;
            }
        }
    }
    printf("%lld\n", *s.lower_bound(n));
    return 0;
}