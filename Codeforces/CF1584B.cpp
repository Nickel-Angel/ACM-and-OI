#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

int n, m;

inline void solve()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", min((m / 3 * 3) * (n / 3) + (m / 3) * (n % 3) + (n + 2) / 3 * (m % 3), (n / 3 * 3) * (m / 3) + (n / 3) * (m % 3) + (m + 2) / 3 * (n % 3)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}