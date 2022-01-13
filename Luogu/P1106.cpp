/*
* @author Nickel_Angel (1239004072@qq.com)
* @copyright Copyright (c) 2022
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

char s[300], t[300];
int n;

int main()
{
    scanf("%s%d", s + 1, &n);
    int len = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= len; ++j)
        {
            if (s[j] > s[j + 1])
            {
                for (int k = j; k <= len; ++k)
                    s[k] = s[k + 1];
                --len;
                break;
            }
        }
    }
    int pos = len;
    for (int i = 1; i <= len; ++i)
    {
        if (s[i] != '0')
        {
            pos = i;
            break;
        }
    }
    for (int i = 1; pos <= len + 1; ++i, ++pos)
        s[i] = s[pos];
    printf("%s\n", s + 1);
    return 0;
}