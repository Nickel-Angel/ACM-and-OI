/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

int a[1010];

inline bool sorted(int a[], const int &n)
{
    int flag = true;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        int ans = 0;
        bool state = 1;
        while (!sorted(a, n))
        {
            if (state)
            {
                for (int i = 1; i < n; i += 2)
                {
                    if (a[i] > a[i + 1])
                        std::swap(a[i], a[i + 1]);
                }
            }
            else
            {
                for (int i = 2; i < n; i += 2)
                {
                    if (a[i] > a[i + 1])
                        std::swap(a[i], a[i + 1]);
                }
            }
            state ^= 1, ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}