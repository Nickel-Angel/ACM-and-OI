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

const int maxn = 3e5 + 10;
int n;
ll ans, bef[40], aft[40];

void solve(int bit, vector<int> &v)
{
    int suf0 = 0, suf1 = 0, tot = v.size();
    ll res0 = 0, res1 = 0;
    for (int i = tot - 1; i >= 0; --i)
    {
        if ((v[i] >> bit) & 1)
        {
            ++suf1;
            res0 += suf0;
        }
        else
        {
            ++suf0;
            res1 += suf1;
        }
    }
    bef[bit] += res0, aft[bit] += res1;
    if (bit == 0)
        return;
    vector<int> a, b;
    for (int x : v)
    {
        if ((x >> bit) & 1)
            a.push_back(x & ((1 << bit) - 1));
        else
            b.push_back(x & ((1 << bit) - 1));
    }
    v.clear();
    if (!a.empty())
        solve(bit - 1, a);
    if (!b.empty())
        solve(bit - 1, b);
}

int main()
{
    scanf("%d", &n);
    vector<int> a(n, 0);
    int max_bit = 0, x = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        for (int j = 30; j >= 0; --j)
        {
            if ((a[i] >> j) & 1)
            {
                max_bit = max(max_bit, j);
                break;
            }
        }
    }
    solve(max_bit, a);
    ll ans = 0;
    for (int i = max_bit; i >= 0; --i)
    {
        if (bef[i] > aft[i])
        {
            x |= (1 << i);
            ans += aft[i];
        }
        else
            ans += bef[i];
    }
    printf("%lld %d\n", ans, x);
    return 0;
}