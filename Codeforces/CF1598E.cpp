/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, q, a[1010][1010];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0)
            {
                int x = i, y = j;
                for (int k = 1; x < n && y < m; ++k)
                {
                    x = i + k / 2, y = j + (k + 1) / 2;
                    if (x >= n || y >= m)
                        break;
                    ans += k;
                }
            }
            if (j == 0)
            {
                int x = i, y = j;
                for (int k = 1; x < n && y < m; ++k)
                {
                    x = i + (k + 1) / 2, y = j + k / 2;
                    if (x >= n || y >= m)
                        break;
                    ans += k; 
                }
            }
        }
    }
    ans += n * m;
    int x, y;
    while (q--)
    {
        scanf("%d%d", &x, &y);
        --x, --y;
        for (int c = 0; c < 2; ++c)
        {
            int nx = x, ny = y, l = 1, r = 1;
            while (nx >= 0 && ny >= 0)
            {
                nx = x - (l + (c ^ 1)) / 2, ny = y - (l + c) / 2;
                //printf("x %d y %d\n", nx, ny);
                if (nx < 0 || ny < 0 || a[nx][ny])
                    break;
                ++l;
            }
            while (nx < n && ny < m)
            {
                nx = x + (r + c) / 2, ny = y + (r + (c ^ 1)) / 2;
                //printf("x %d y %d\n", nx, ny);
                if (nx >= n || ny >= m || a[nx][ny])
                    break;
                ++r; 
            }
            //printf("l %d r %d\n", l, r);
            if (a[x][y])
                ans += l * r;
            else
                ans -= l * r;
        }
        if (a[x][y])
            --ans;
        else
            ++ans;
        a[x][y] ^= 1;
        printf("%lld\n", ans);
    }
    return 0;
}