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

ll a, b;

int main()
{
    scanf("%lld%lld", &a, &b);
    ll ans = 0;
    while (a != b)
    {
        if (a < b)
            swap(a, b);
        //printf("%lld %lld\n", a, b);
        if (a % b == 0)
        {
            ans += a / b - 1;
            break;
        }
        ans += a / b;
        a = a % b;
    }
    printf("%lld\n", ans);
    return 0;
}