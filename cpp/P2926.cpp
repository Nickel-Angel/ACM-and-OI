#include <algorithm>
#include <cstdio>
#include <iostream>

const int maxn = 2e5 + 10;
const int bound = 5e5;
int n, a[maxn];
int cnt[bound + 10], ans[bound + 10]; 

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    for (int i = 1; i <= bound; ++i)
    {
        if (!cnt[i]) continue;
        for (int j = 1; j <= bound / i; ++j)
            ans[i * j] += cnt[i];
        --ans[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res += ans[a[i]];
    printf("%lld\n", res);
    return 0;
}