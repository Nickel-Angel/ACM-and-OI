#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

inline void solve()
{
    long long u, v;
    scanf("%lld%lld", &u, &v);
    printf("%lld %lld\n", u * u, -v * v);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}