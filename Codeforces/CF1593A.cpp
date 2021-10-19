/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::max;
using std::sort;
using std::swap;

int a[5], id[5];

inline void solve()
{
    id[0] = 0, id[1] = 1, id[2] = 2;
    scanf("%d%d%d", a, a + 1, a + 2);
    sort(id, id + 3, [&](int x, int y){return a[x] < a[y];});
    if (a[id[2]] == a[id[1]])
    {
        if (a[id[0]] == a[id[1]])
            printf("1 1 1");
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                if (a[i] != a[id[2]])
                    printf("%d ", a[id[2]] - a[i] + 1);
                else
                    printf("1 ");
            }
        }
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            if (a[i] == a[id[2]])
                printf("0 ");
            else
                printf("%d ", a[id[2]] - a[i] + 1);
        }
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}