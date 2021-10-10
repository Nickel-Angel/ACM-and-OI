/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 2e5 + 10;
int n, q, m, x[maxn], y[maxn], day[450][450], date[maxn], s[maxn];

inline void add(int t, int i, int key)
{
    int len = x[i] + y[i];
    int l = (t + x[i]) % len, r = (t - 1) % len;
    if (l <= r)
    {
        for (int j = l; j <= r; ++j)
            day[len][j] += key;
    }
    else
    {
        for (int j = 0; j <= r; ++j)
            day[len][j] += key;
        for (int j = l; j < len; ++j)
            day[len][j] += key;
    }
}

inline int query(int t)
{
    int res = 0;
    for (int i = 2; i <= m; ++i)
        res += day[i][t % i];
    return res;
}

int main()
{
    scanf("%d%d", &n, &q);
    m = sqrt(n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", x + i, y + i);
    int opt, k, ans = 0;
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d", &opt, &k);
        if (opt == 1)
        {
            if (x[k] + y[k] >= m)
            {
                for (int j = i + x[k]; j <= q; j += x[k] + y[k])
                {
                    ++date[j];
                    if (j + y[k] <= q)
                        --date[j + y[k]];
                }
            }
            else
                add(i, k, 1);
            s[k] = i;
        }
        else
        {
            if (x[k] + y[k] >= m)
            {
                for (int j = s[k] + x[k]; j <= q; j += x[k] + y[k])
                {
                    --date[j];
                    if (j + y[k] <= q)
                        ++date[j + y[k]];
                    if (j < i && j + y[k] >= i)
                        --ans;
                }
            }
            else
                add(s[k], k, -1);
        }
        ans += date[i];
        printf("%d\n", ans + query(i));
    }
    return 0;
}