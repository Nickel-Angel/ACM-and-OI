/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2021
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 5e5 + 10;
int n, a[maxn << 1], L[2], R[2];
char ans[maxn << 1];

inline bool calc()
{    
    for (int i = 1; i < n; ++i)
    {
        if (L[0] <= R[0] && ((L[1] <= R[1] && a[L[0]] == a[L[1]]) || (L[0] < R[0] && a[L[0]] == a[R[0]])))
        {
            if (L[0] < R[0] && a[L[0]] == a[R[0]])
            {
                ans[i] = 'L';
                ans[2 * (n - 1) - i + 1] = 'L';
                ++L[0], --R[0];
            }
            else
            {
                ans[i] = 'L';
                ans[2 * (n - 1) - i + 1] = 'R';
                ++L[0], ++L[1];
            }
        }
        else if (L[1] <= R[1] && ((L[0] <= R[0] && a[R[0]] == a[R[1]]) || (L[1] < R[1] && a[L[1]] == a[R[1]])))
        {
            if (L[0] <= R[0] && a[R[0]] == a[R[1]])
            {
                ans[i] = 'R';
                ans[2 * (n - 1) - i + 1] = 'L';
                --R[0], --R[1];
            }
            else
            {
                ans[i] = 'R';
                ans[2 * (n - 1) - i + 1] = 'R';
                ++L[1], --R[1];
            }
        }
        else
            return false;
    }
    return true;
}

inline void solve()
{
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
        scanf("%d", a + i);
    int x = 0;
    for (int i = 2; i <= 2 * n; ++i)
    {
        if (a[i] == a[1])
        {
            x = i;
            break;
        }
    }
    L[0] = 2, R[0] = x - 1, L[1] = x + 1, R[1] = 2 * n;
    if (calc())
    {
        printf("L%sL\n", ans + 1);
        return;
    }
    for (int i = 1; i < 2 * n; ++i)
    {
        if (a[i] == a[2 * n])
        {
            x = i;
            break;
        }       
    }
    L[0] = 1, R[0] = x - 1, L[1] = x + 1, R[1] = 2 * n - 1;
    if (calc())
    {
        printf("R%sL\n", ans + 1);
        return;
    }
    puts("-1");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}