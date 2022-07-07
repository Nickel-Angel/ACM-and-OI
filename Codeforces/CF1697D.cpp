/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>

int n, last_pos[30], id[30], tot;
char s[1010];

inline char query_letter(int x)
{
    static char res;
    printf("? 1 %d\n", x);
    fflush(stdout);
    scanf(" %c", &res);
    return res;
}

inline int query_diff(int l, int r)
{
    static int res;
    printf("? 2 %d %d\n", l, r);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    s[1] = query_letter(1), tot = 1;
    id[1] = s[1] - 'a', last_pos[1] = 1; 
    for (int i = 2, l, r, mid, diff; i <= n; ++i)
    {
        l = 1, r = tot;
        while (l < r)
        {
            mid = (l + r + 1) >> 1, diff = query_diff(last_pos[mid], i);
            if (diff > tot - mid + 1)
                r = mid - 1;
            else
                l = mid;
        }
        if (l == 1 && query_diff(last_pos[l], i) > tot - l + 1)
        {
            s[i] = query_letter(i);
            id[++tot] = s[i] - 'a', last_pos[tot] = i;
        }
        else
        {
            s[i] = id[l] + 'a';
            for (int j = l; j < tot; ++j)
            {
                id[j] = id[j + 1];
                last_pos[j] = last_pos[j + 1];
            }
            id[tot] = s[i] - 'a', last_pos[tot] = i;
        }
    }
    printf("! ");
    for (int i = 1; i <= n; ++i)
        putchar(s[i]);
    return 0;
}