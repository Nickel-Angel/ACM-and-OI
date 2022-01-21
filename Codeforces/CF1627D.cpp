/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 1e6 + 10;
int n, a[maxn], cnt[maxn];

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}

int main()
{
    scanf("%d", &n);
    int bound = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        cnt[a[i]] = 1;
        bound = std::max(bound, a[i]);
    }
    int flag, ans = 0;
    for (int i = bound; i > 0; --i)
    {
        if (cnt[i])
            continue;
        flag = 0;
        for (int j = 2 * i; j <= bound && flag != 1; j += i)
        {
            if (cnt[j])
                flag = flag ? gcd(flag, j / i) : j / i;
        }
        if (flag == 1)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}