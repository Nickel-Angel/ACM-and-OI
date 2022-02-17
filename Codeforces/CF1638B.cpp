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
int n;
vector<int> odd, even;

inline void solve()
{
    odd.clear(), even.clear();
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        if (x & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    bool flag = true;
    for (unsigned i = 1; i < odd.size(); ++i)
        flag &= (odd[i] >= odd[i - 1]);
    for (unsigned i = 1; i < even.size(); ++i)
        flag &= (even[i] >= even[i - 1]);
    puts(flag ? "YES" : "NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}