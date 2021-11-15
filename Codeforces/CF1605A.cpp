#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

int a, b, c;

inline void solve()
{
    scanf("%d%d%d", &a, &b, &c);
    int s = abs(a + c - 2 * b);
    if (s % 3 == 2)
    {
        puts("1");
        return;
    }
    printf("%d\n", s % 3);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}