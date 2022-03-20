/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;
int n, q, m, a[maxn], d[maxn], f[maxn];

int main()
{
    scanf("%d%d%d", &n, &q, &m);
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= n + 2; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    int cnt = 0;
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        a[i] = (a[i] - x + m) % m;
        d[i] = a[i];
        if (i > 1)
            d[i] = (d[i] - a[i - 1] + m) % m;
        if (i > 2)
            d[i] = (d[i] - a[i - 2] + m) % m;
        cnt += (d[i] == 0);
    }
    char opt;
    int l, r;
    while (q--)
    {
        scanf(" %c%d%d", &opt, &l, &r);
        cnt -= (d[l] == 0);
        if (r < n)
            cnt -= (d[r + 1] == 0);
        if (r < n - 1)
            cnt -= (d[r + 2] == 0);
        if (opt == 'A')
        {
            d[l] = (d[l] + f[1]) % m;
            if (r < n)
                d[r + 1] = (d[r + 1] - f[r - l + 2] + m) % m;
            if (r < n - 1)
                d[r + 2] = (d[r + 2] - f[r - l + 1] + m) % m;
        }
        else
        {
            d[l] = (d[l] - f[1] + m) % m;
            if (r < n)
                d[r + 1] = (d[r + 1] + f[r - l + 2]) % m;
            if (r < n - 1)
                d[r + 2] = (d[r + 2] + f[r - l + 1]) % m;
        }
        cnt += (d[l] == 0);
        if (r < n)
            cnt += (d[r + 1] == 0);
        if (r < n - 1)
            cnt += (d[r + 2] == 0);
        puts(cnt == n ? "Yes" : "No");
    }
    return 0;
}