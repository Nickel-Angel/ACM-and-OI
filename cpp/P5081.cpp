#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e7 + 10;
const int p = 20040313;
int n, inv[maxn];

int main()
{
    scanf("%d", &n);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (p - p / i) * inv[p % i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + inv[i]) % p;
    ans = 1ll * ans * n % p;
    printf("%d\n", ans);
    return 0;
}