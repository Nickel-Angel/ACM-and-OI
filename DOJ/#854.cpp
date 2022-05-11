/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int a[3][3];

inline void solve()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            scanf("%d", a[i] + j);
    }
    int ans = 0, flag, res;
    for (int xa = 0; xa < 3; ++xa)
    {
        for (int ya = 0; ya < 3; ++ya)
        {
            flag = 1;
            for (int xb = 0; xb < 3; ++xb)
            {
                if (xa == xb)
                    continue;
                for (int yb = 0; yb < 3; ++yb)
                {
                    if (ya == yb)
                        continue;
                    res = 0;
                    for (int i = 0; i < 3; ++i)
                    {
                        for (int j = 0; j < 3; ++j)
                        {
                            if (i == xa && j == ya)
                                continue;
                            if (i == xb && j == yb)
                                continue;
                            if (i != xa && j != ya && i != xb && j != yb)
                                res ^= a[i][j];
                            else
                                res ^= (a[i][j] - 1);
                        }
                    }
                    flag &= (res != 0);
                }
            }
            ans += flag;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}