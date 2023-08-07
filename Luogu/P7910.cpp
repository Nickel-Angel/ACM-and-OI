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

const int maxn = 2e5 + 10;
int n, a[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int x = 0, y = 0;
    for (int i = n; i > 0; --i)
    {
        if (a[i] < a[n])
        {
            if (!x)
                x = a[i];
            else if (a[i] < x)
            {
                y = a[i];
                break;
            }
        }
    }
    if (!x)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", std::max(a[n] % x, y));
    return 0;
}